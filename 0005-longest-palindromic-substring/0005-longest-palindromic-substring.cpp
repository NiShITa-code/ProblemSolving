class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        string ans = "";
        int maxLength = 0;
        // we iterate diagonally
        for (int diff = 0; diff < n; diff++) {
            for (int i = 0; i + diff < n; i++) {
                int j = i + diff;
                // 1 len all palindromes
                if (i == j) {
                    dp[i][j] = 1;
                }
                // 2 len string if both chars equal is a palindrome if not not a palindrome
                else if (diff == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 2;
                    } else {
                        dp[i][j] = 0;
                    }
                }
                // now for rest of len first check last chars if they are equal 
                // and if reamining inner string is salso a palindrome
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1] > 0) {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    } 
                }
                // if this string is a palindrome
                if (dp[i][j] != 0) {
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
                
        }
        return ans;
    }
};