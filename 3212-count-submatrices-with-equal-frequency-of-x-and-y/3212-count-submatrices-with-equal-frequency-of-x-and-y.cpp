class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> xCol(cols, 0), yCol(cols, 0);
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            int rowX = 0, rowY = 0;

            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'X') rowX++;
                else if (grid[i][j] == 'Y') rowY++;

                xCol[j] += rowX;
                yCol[j] += rowY;

                if (xCol[j] == yCol[j] && xCol[j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
        
    }
};