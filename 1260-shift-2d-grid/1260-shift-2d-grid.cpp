class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n));

        int total = m * n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int curr = i * n + j;
                int next = (curr + k) % total;

                int row = next / n;
                int col = next % n;

                ans[row][col] = grid[i][j];
            }
        }

        return ans;
    }
};