class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map <int, int> frequency;
        for(int i = 0; i < nums.size(); i++) {
            frequency[nums[i]]++;
        }
        for(auto f: frequency) {
            int val = f.second;
            ans += (val * (val - 1))/2;
        }
        return ans;
    }
};