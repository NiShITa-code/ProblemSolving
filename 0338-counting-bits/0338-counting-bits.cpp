class Solution {
public:
    int noOfOnes(int i) {
        int setBits = 0;
        while (i > 0) {
            i = i & (i - 1);
            setBits++;
        }
        return setBits;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i] = noOfOnes(i);
        }
        return ans;
    }
};