class Solution {
public:
    int reverseNumber(int n) {
        int num = 0;
        while(n > 0) {
            num = num * 10 + (n % 10);
            n/= 10;
        }
        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int minDist = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i])) {
                minDist = min(minDist, i - mp[nums[i]]);
            }
            int reversedNum = reverseNumber(nums[i]);
            mp[reversedNum] = i;
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};