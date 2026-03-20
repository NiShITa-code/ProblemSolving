class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for(int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> subMat;
                subMat.reserve(k*k);

                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        subMat.push_back(grid[r][c]);
                    }
                }

                sort(subMat.begin(), subMat.end());

                int minDiff = INT_MAX;

                for (int p = 1; p < (int)subMat.size(); p++) {
                    if (subMat[p] != subMat[p - 1]) {
                        minDiff = min(minDiff, subMat[p] - subMat[p - 1]);
                    }
                }

                // all elements same
                ans[i][j] = (minDiff == INT_MAX ? 0 : minDiff);

            }
        }
        return ans;
    }
};