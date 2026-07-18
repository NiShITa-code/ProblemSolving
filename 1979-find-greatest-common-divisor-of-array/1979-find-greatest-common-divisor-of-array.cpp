class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];

        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        return gcd(mx, mn);
    }
};