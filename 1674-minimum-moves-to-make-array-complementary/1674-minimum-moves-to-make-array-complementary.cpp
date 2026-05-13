#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int sum = a + b;

            // Start with 2 moves for every possible sum
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // In range [low, high], only 1 move is needed
            diff[low] -= 1;
            diff[high + 1] += 1;

            // At exact sum, 0 moves are needed
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int moves = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            moves += diff[s];
            ans = min(ans, moves);
        }

        return ans;
    }
};