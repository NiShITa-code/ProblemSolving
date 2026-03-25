class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalSum = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++){
                totalSum += grid[r][c];
            }
        }
        if (totalSum % 2 != 0) {
            return false;
        }
        long long target = totalSum / 2;

        // horizontal cut
        long long topPartSum = 0;
        for (int r = 0; r < n - 1; r++) {
            for (int c = 0; c < m; c++) {
                topPartSum += grid[r][c];
            }
            if (topPartSum == target) {
                return true;
            }
        }

        long long leftPartSum = 0;
        for (int c = 0; c < m - 1; c++) {
            for (int r = 0; r < n; r++) {
                leftPartSum += grid[r][c];
            }
            if (leftPartSum == target) {
                return true;
            }
        }

        return false;
    }
};