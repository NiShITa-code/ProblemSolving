class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 1));

        // Prefix product
        long long prefix = 1;
        for (int idx = 0; idx < n * m; idx++) {
            int r = idx / m;
            int c = idx % m;

            ans[r][c] = prefix;
            prefix = (prefix * (grid[r][c] % MOD)) % MOD;
        }

        // Suffix product
        long long suffix = 1;
        for (int idx = n * m - 1; idx >= 0; idx--) {
            int r = idx / m;
            int c = idx % m;

            ans[r][c] = (ans[r][c] * suffix) % MOD;
            suffix = (suffix * (grid[r][c] % MOD)) % MOD;
        }

        return ans;
    }
};