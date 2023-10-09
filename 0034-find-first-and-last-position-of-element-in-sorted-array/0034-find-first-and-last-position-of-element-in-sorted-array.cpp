class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }
        int li = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (li == n || nums[li] !=  target) {
            return {-1, -1};
        }
        int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {li, hi - 1};
    }
};