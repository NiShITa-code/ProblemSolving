class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffixMin(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        vector<int> ans(n);

        int start = 0;
        int currentMax = nums[0];

        for (int i = 0; i < n; ++i) {
            currentMax = max(currentMax, nums[i]);

            // No inversion crosses from [start..i] to [i+1..n-1]
            if (currentMax <= suffixMin[i + 1]) {
                for (int j = start; j <= i; ++j) {
                    ans[j] = currentMax;
                }

                start = i + 1;
                if (start < n) currentMax = nums[start];
            }
        }

        return ans;
    }
};