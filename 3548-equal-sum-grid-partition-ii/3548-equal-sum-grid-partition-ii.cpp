class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        const int MAX_VAL = 100000;

        long long totalSum = 0;

        // Build total sum and initial "whole grid" frequency together
        vector<int> remainingFreq(MAX_VAL + 1, 0);
        for (const auto& row : grid) {
            for (int val : row) {
                totalSum += val;
                remainingFreq[val]++;
            }
        }

        auto canRemoveFromRectangle = [&](int r1, int r2, int c1, int c2,
                                          long long diff,
                                          const vector<int>& freq) -> bool {
            if (diff <= 0 || diff > MAX_VAL) return false;

            int height = r2 - r1 + 1;
            int width = c2 - c1 + 1;
            long long area = 1LL * height * width;

            // cannot remove the only cell
            if (area <= 1) return false;

            // General rectangle: any cell can be removed
            if (height > 1 && width > 1) {
                return freq[(int)diff] > 0;
            }

            // Single row: only endpoints allowed
            if (height == 1) {
                return grid[r1][c1] == diff || grid[r1][c2] == diff;
            }

            // Single column: only endpoints allowed
            return grid[r1][c1] == diff || grid[r2][c1] == diff;
        };

        // --------------------------------------------------
        // Try horizontal cuts
        // top part grows row by row
        // --------------------------------------------------
        vector<int> topFreq(MAX_VAL + 1, 0);
        vector<int> bottomFreq = remainingFreq;

        long long topSum = 0;

        for (int r = 0; r < rows - 1; r++) {
            for (int c = 0; c < cols; c++) {
                int val = grid[r][c];
                topSum += val;
                topFreq[val]++;
                bottomFreq[val]--;
            }

            long long bottomSum = totalSum - topSum;

            if (topSum == bottomSum) return true;

            if (topSum > bottomSum) {
                long long diff = topSum - bottomSum;
                if (canRemoveFromRectangle(0, r, 0, cols - 1, diff, topFreq)) {
                    return true;
                }
            } else {
                long long diff = bottomSum - topSum;
                if (canRemoveFromRectangle(r + 1, rows - 1, 0, cols - 1, diff, bottomFreq)) {
                    return true;
                }
            }
        }

        // --------------------------------------------------
        // Try vertical cuts
        // left part grows column by column
        // --------------------------------------------------
        vector<int> leftFreq(MAX_VAL + 1, 0);
        vector<int> rightFreq = remainingFreq;

        long long leftSum = 0;

        for (int c = 0; c < cols - 1; c++) {
            for (int r = 0; r < rows; r++) {
                int val = grid[r][c];
                leftSum += val;
                leftFreq[val]++;
                rightFreq[val]--;
            }

            long long rightSum = totalSum - leftSum;

            if (leftSum == rightSum) return true;

            if (leftSum > rightSum) {
                long long diff = leftSum - rightSum;
                if (canRemoveFromRectangle(0, rows - 1, 0, c, diff, leftFreq)) {
                    return true;
                }
            } else {
                long long diff = rightSum - leftSum;
                if (canRemoveFromRectangle(0, rows - 1, c + 1, cols - 1, diff, rightFreq)) {
                    return true;
                }
            }
        }

        return false;
    }
};