class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int cols = coins[0].size();
        const int NEG_INF = INT_MIN / 2;

        // dp[c][k]:
        // maximum money after reaching current row, column c-1,
        // with at most k neutralizations available in total.
        vector<vector<int>> dp(cols + 1, vector<int>(3, NEG_INF));

        // Starting trick:
        // before processing first cell, pretend we can enter it with profit 0
        for (int k = 0; k < 3; k++) {
            dp[1][k] = 0;
        }

        for (const auto& row : coins) {
            for (int c = 1; c <= cols; c++) {
                int value = row[c - 1];

                // State with 2 neutralizations possible
                dp[c][2] = max({
                    dp[c - 1][2] + value, // from left, take value normally
                    dp[c][2] + value,     // from top, take value normally
                    dp[c - 1][1],         // from left, neutralize this cell
                    dp[c][1]              // from top, neutralize this cell
                });

                // State with 1 neutralization possible
                dp[c][1] = max({
                    dp[c - 1][1] + value, // from left, take value normally
                    dp[c][1] + value,     // from top, take value normally
                    dp[c - 1][0],         // from left, neutralize this cell
                    dp[c][0]              // from top, neutralize this cell
                });

                // State with 0 neutralizations possible
                dp[c][0] = max(dp[c - 1][0], dp[c][0]) + value;
            }
        }

        return dp[cols][2];
    }
};