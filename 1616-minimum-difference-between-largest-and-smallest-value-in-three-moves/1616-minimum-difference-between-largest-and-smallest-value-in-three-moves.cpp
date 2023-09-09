class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int opt1 = abs(nums[0] - nums[n - 4]);
        int opt2 = abs(nums[3] - nums[n - 1]);
        int opt3 = abs(nums[1] - nums[n - 3]);
        int opt4 = abs(nums[2] - nums[n - 2]);

        return min(min(opt1, opt2), min(opt3, opt4));
    }
};