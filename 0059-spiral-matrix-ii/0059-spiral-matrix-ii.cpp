class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<int> dirX= {0, 1, 0, -1};
        vector<int> dirY = {1, 0, -1, 0};
        int val = 1;
        int dir = 0;
        int r = 0;
        int c = 0;
        while(val <= n*n) {
            matrix[r][c] = val;
            int nr = r + dirX[dir];
            int nc = c + dirY[dir];
            if (nr < 0 || nc < 0 || nr >= n || nc>= n || matrix[nr][nc] != 0) {
                dir = (dir + 1) % 4;
                nr = r + dirX[dir];
                nc = c + dirY[dir];
            }

            r = nr;
            c = nc;
            val++;
        }
        return matrix;

    }
};