class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            result[i] = nums[((i + nums[i]) % n + n) % n];
        }
        return result;
    }
};