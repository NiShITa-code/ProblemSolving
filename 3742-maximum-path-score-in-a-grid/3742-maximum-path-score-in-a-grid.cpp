class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        const int NEG = -1e9;

        vector<vector<int>> prev(n, vector<int>(k + 1, NEG));
        vector<vector<int>> curr(n, vector<int>(k + 1, NEG));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fill(curr[j].begin(), curr[j].end(), NEG);
            }

            for (int j = 0; j < n; j++) {
                int value = grid[i][j];
                int cost = value == 0 ? 0 : 1;

                for (int used = cost; used <= k; used++) {
                    if (i == 0 && j == 0) {
                        curr[j][0] = 0;
                        continue;
                    }

                    int best = NEG;

                    if (i > 0) {
                        best = max(best, prev[j][used - cost]);
                    }

                    if (j > 0) {
                        best = max(best, curr[j - 1][used - cost]);
                    }

                    if (best != NEG) {
                        curr[j][used] = best + value;
                    }
                }
            }

            swap(prev, curr);
        }

        int ans = NEG;

        for (int used = 0; used <= k; used++) {
            ans = max(ans, prev[n - 1][used]);
        }

        return ans == NEG ? -1 : ans;
    }
};