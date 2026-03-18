class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        vector<long long> colSum(c, 0);
        int ans = 0;
        for(int i = 0; i < r; i++) {
            long long rowSumTillNow = 0;
            for (int j = 0; j < c; j++) {
                rowSumTillNow += grid[i][j];
                colSum[j] += rowSumTillNow;   // sum of rectangle (0,0) to (i,j)
                if (colSum[j] <= k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};