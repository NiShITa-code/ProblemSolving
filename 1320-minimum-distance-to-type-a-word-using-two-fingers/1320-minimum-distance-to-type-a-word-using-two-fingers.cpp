class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        
        // dp[f1][f2] = min cost till current step
        vector<vector<int>> dp(27, vector<int>(27, 1e9));
        dp[26][26] = 0; // both fingers unused

        for (char c : word) {
            int cur = c - 'A';
            vector<vector<int>> newdp(27, vector<int>(27, 1e9));

            for (int f1 = 0; f1 <= 26; f1++) {
                for (int f2 = 0; f2 <= 26; f2++) {
                    int val = dp[f1][f2];
                    if (val == 1e9) continue;

                    // move finger1
                    newdp[cur][f2] = min(newdp[cur][f2],
                        val + dist(f1 == 26 ? -1 : f1, cur));

                    // move finger2
                    newdp[f1][cur] = min(newdp[f1][cur],
                        val + dist(f2 == 26 ? -1 : f2, cur));
                }
            }
            dp = newdp;
        }

        int ans = 1e9;
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};