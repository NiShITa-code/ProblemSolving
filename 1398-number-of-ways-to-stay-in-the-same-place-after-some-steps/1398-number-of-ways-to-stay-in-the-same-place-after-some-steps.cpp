class Solution {
public:
    vector<vector<int>> memo;
    int MOD = 1e9 + 7;
    int dp(int curr, int remain, int arrLen) {
        if (remain == 0) {
            if (curr == 0) {
                return 1;
            }
            return 0;
        }
        
        if (memo[curr][remain] != -1) {
            return memo[curr][remain];
        }

        int ans = dp(curr, remain - 1, arrLen);
        if (curr > 0) {
            ans = (ans + dp(curr - 1, remain - 1, arrLen)) % MOD;
        }
        
        if (curr < arrLen - 1) {
            ans = (ans + dp(curr + 1, remain - 1, arrLen)) % MOD;
        }
        
        memo[curr][remain] = ans;
        return ans;
    }
    
    int numWays(int steps, int arrLen) {
        
        //he furthest we can go is by only making moves to the right, but we would run out of moves after steps moves.
        arrLen = min(arrLen, steps); 
        memo = vector(arrLen, vector(steps + 1, -1));
        return dp(0, steps, arrLen);
    }
};