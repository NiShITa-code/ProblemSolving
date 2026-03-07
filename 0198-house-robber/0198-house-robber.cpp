class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> maxMoney(nums.size(), -1);
        maxMoney[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int rob = nums[i];
            if (i > 1) {
                rob += maxMoney[i - 2];
            }
            int notRob = maxMoney[i - 1];
            maxMoney[i] = max(rob, notRob);
        }
        return maxMoney[nums.size() - 1];
    }
};