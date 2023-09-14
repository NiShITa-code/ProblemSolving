class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // here we are computing each row from next row
        int n = triangle.size();
        vector<int> front(n, 0);
        
        // last row
        for (int j = 0; j < n; j++) {
            front[j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 0);
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j + 1];
                curr[j] = min(down, diag);
            }
            front = curr;
        }
        return front[0];
    }
};