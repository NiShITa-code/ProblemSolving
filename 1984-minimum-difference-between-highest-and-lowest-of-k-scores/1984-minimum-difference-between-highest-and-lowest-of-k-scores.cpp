class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        sort(nums.begin(), nums.end());
        int left = 0;
        int result = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            if (right - left + 1 == k) {
                result = min(result, nums[right] - nums[left]);
                left++;
            }
        }
        return result;
    }
};