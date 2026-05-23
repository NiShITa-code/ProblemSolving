class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return true;
        }
        int reverseNum = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]){
                reverseNum++;
            }
            if (reverseNum > 1) {
                return false;
            }
        }

        if (nums[0] < nums[n -1]) {
            reverseNum++;
        }

        return reverseNum <= 1;
    }
};