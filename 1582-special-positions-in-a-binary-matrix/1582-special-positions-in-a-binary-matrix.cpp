class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int nrow = mat.size();
        int ncol = mat[0].size();
        int ans = 0;
        vector<int> rowOneCount(nrow, 0);
        vector<int> colOneCount(ncol, 0);
        for(int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncol; j++) {
                if (mat[i][j] == 1){
                    rowOneCount[i]++;
                    colOneCount[j]++;
                }
            }
        }

        for (int i = 0; i < nrow; i++) {
            if (rowOneCount[i] != 1) {
                continue;
            } 
            for(int j = 0; j < ncol; j++) {
                if (mat[i][j] == 1 && colOneCount[j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};