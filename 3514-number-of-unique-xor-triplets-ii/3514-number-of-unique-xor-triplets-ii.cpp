class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;   // XOR values: 0...2047

        // dp[k][x] = can we obtain XOR x using exactly k distinct elements?
        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));

        dp[0][0] = true;

        for (int num : nums) {
            // Iterate backwards to avoid using the same element multiple times
            for (int k = 2; k >= 0; k--) {
                for (int x = 0; x < MAXX; x++) {
                    if (dp[k][x]) {
                        dp[k + 1][x ^ num] = true;
                    }
                }
            }
        }

        int ans = 0;

        // dp[1] -> XORs from one element
        // dp[3] -> XORs from three distinct elements
        for (int x = 0; x < MAXX; x++) {
            if (dp[1][x] || dp[3][x])
                ans++;
        }

        return ans;
    }
};