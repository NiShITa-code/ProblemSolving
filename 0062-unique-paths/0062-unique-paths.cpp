class Solution {
public:
    int uniquePaths(int m, int n) {
        /* using optimised dp
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];*/
        //using math we need m+n-2 directions in total
        //now to fill m+n-2 we will go with either m+n-2Cn-1 or m+n-2Cm-1
        
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    
    }

    
};