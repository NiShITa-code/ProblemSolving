class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();

        int shift = k % cols;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int newCol;

                if (r % 2 == 0) {
                    // even row: left shift
                    newCol = (c + shift) % cols;
                } else {
                    // odd row: right shift
                    newCol = (c - shift + cols) % cols;
                }

                if (mat[r][c] != mat[r][newCol]) {
                    return false;
                }
            }
        }

        return true;
    }
};