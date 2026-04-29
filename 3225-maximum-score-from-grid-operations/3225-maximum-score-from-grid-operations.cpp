#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        if (n == 1) return 0;

        // prefix[col][h] = sum of grid[0][col] to grid[h - 1][col]
        vector<vector<long long>> prefix(n, vector<long long>(n + 1, 0));

        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                prefix[col][row + 1] = prefix[col][row] + grid[row][col];
            }
        }

        auto gain = [&](int col, int selfH, int neighborH) -> long long {
            if (neighborH <= selfH) return 0LL;

            return prefix[col][neighborH] - prefix[col][selfH];
        };

        int H = n + 1;
        long long NEG = -4e18;

        // dp[prevH][currH]
        // heights of previous and current column
        // score finalized up to previous column
        vector<vector<long long>> dp(H, vector<long long>(H, NEG));

        // Initialize columns 0 and 1.
        // Column 0 only has right neighbor column 1.
        for (int h0 = 0; h0 < H; h0++) {
            for (int h1 = 0; h1 < H; h1++) {
                dp[h0][h1] = gain(0, h0, h1);
            }
        }

        // Process middle columns
        for (int col = 1; col < n - 1; col++) {
            vector<vector<long long>> newDp(H, vector<long long>(H, NEG));

            for (int currH = 0; currH < H; currH++) {
                vector<long long> prefixBest(H, NEG);
                vector<long long> suffixBest(H + 1, NEG);

                long long best = NEG;

                // prefixBest[x] =
                // max dp[prevH][currH] for prevH <= x
                for (int prevH = 0; prevH < H; prevH++) {
                    best = max(best, dp[prevH][currH]);
                    prefixBest[prevH] = best;
                }

                best = NEG;

                // suffixBest[x] =
                // max dp[prevH][currH] + gain(col, currH, prevH)
                // for prevH >= x
                for (int prevH = H - 1; prevH >= 0; prevH--) {
                    best = max(best, dp[prevH][currH] + gain(col, currH, prevH));
                    suffixBest[prevH] = best;
                }

                for (int nextH = 0; nextH < H; nextH++) {
                    // We want:
                    // dp[prevH][currH] + gain(col, currH, max(prevH, nextH))

                    // Case 1: prevH <= nextH
                    // max(prevH, nextH) = nextH
                    long long option1 = prefixBest[nextH] + gain(col, currH, nextH);

                    // Case 2: prevH > nextH
                    // max(prevH, nextH) = prevH
                    long long option2 = suffixBest[nextH + 1];

                    newDp[currH][nextH] = max(option1, option2);
                }
            }

            dp = newDp;
        }

        long long ans = 0;

        // Finalize last column.
        // Last column only has left neighbor.
        for (int prevH = 0; prevH < H; prevH++) {
            for (int lastH = 0; lastH < H; lastH++) {
                ans = max(ans, dp[prevH][lastH] + gain(n - 1, lastH, prevH));
            }
        }

        return ans;
    }
};