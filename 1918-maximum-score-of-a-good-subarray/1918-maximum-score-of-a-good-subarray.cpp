class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
       int n = nums.size();
       int left = k;
       int right = k;
       int ans = nums[k];
       int minEle = nums[k];

       while (left > 0 || right < n - 1) {
           if ((left > 0 ? nums[left - 1] : 0) < (right < n - 1? nums[right + 1] : 0)) {
               right++;
               minEle = min(minEle, nums[right]);
           } else {
               left--;
               minEle = min(minEle, nums[left]);
           }
           ans = max(ans, minEle * (right - left + 1));
       }
       return ans;
    }
};