class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {

            // If n is even, no valid x exists
            // ans since nums can have only prime number only case is 2
            if (n == 2) {
                ans.push_back(-1);
                continue;
            }

            /*
             Example:
             n = 79
             Binary: 1001111

             Trailing 1s are:
             1001111
                ↑↑↑↑

             We scan from the right:
             - Skip all trailing 1s
             - Stop at the first 0

             100[0]1111  ← stop here

             The bit we need to flip is the FIRST trailing 1:
             100[1]111   ← flip this bit 
            */

            int t = 1;

            // Move t left while we are on trailing 1s
            // This finds the first 0 after trailing 1s
            while (n & t) {
                t <<= 1;
            }

            /*
             After the loop (for n = 79):
             t = 0010000   (first 0 after trailing 1s)
             t >> 1 = 0001000  (first trailing 1)

             Flip that bit using XOR:
             1001111
           ^ 0001000
             --------
             1000111 = 71
            */

            int x = n ^ (t >> 1);
            ans.push_back(x);
        }

        return ans;
    }
};
