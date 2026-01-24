class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int maxSum = 0;
        while(i < j) {
            int sum = nums[i] + nums[j];
            maxSum = max(maxSum, sum);
            i++;
            j--;
        }
        return maxSum;
    }
};