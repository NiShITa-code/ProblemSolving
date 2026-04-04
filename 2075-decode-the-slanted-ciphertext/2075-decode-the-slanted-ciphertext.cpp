class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        // If empty, nothing to decode
        if (encodedText.empty()) return "";

        int totalLen = encodedText.size();

        // Number of columns in the matrix
        // because matrix is filled row-wise:
        // totalLen = rows * cols
        int cols = totalLen / rows;

        string result;

        // Optional optimization: avoid resizing overhead
        result.reserve(totalLen);

        // We start from each column in the first row
        for (int startCol = 0; startCol < cols; startCol++) {

            int r = 0;              // start from row 0
            int c = startCol;       // start from this column

            // Move diagonally: (r+1, c+1)
            while (r < rows && c < cols) {

                // Convert (r, c) → index in 1D string
                result.push_back(encodedText[r * cols + c]);

                r++;
                c++;
            }
        }

        // Remove trailing spaces (these were padding cells)
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};