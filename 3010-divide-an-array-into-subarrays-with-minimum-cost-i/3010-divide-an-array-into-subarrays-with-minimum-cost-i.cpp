class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        int firstMin = 51;
        int secMin = 51;
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num < firstMin) {
                secMin = firstMin;
                firstMin = num;
            }
            else if (num < secMin) {
                secMin = num;
            }
        }
        return ans + firstMin + secMin;
    }
};