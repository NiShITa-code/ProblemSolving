class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            int distinctEven = 0;
            int distinctOdd = 0;

            for (int j = i; j < n; j++) {
                if (freq[nums[j]] == 0) {
                    if (nums[j] % 2 == 0)
                        distinctEven++;
                    else
                        distinctOdd++;
                }

                freq[nums[j]]++;

                if (distinctEven == distinctOdd) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};