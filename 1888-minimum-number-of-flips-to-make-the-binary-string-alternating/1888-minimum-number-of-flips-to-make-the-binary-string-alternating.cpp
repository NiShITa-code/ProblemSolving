class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;
        int left = 0;

        for (int right = 0; right < 2 * n; right++) {
            char expected1 = (right % 2 == 0) ? '0' : '1'; // 0101...
            char expected2 = (right % 2 == 0) ? '1' : '0'; // 1010...

            if (s[(right % n)] != expected1) diff1++;
            if (s[(right % n)] != expected2) diff2++;

            // Keep window size at most n
            if (right - left + 1 > n) {
                char leftExpected1 = (left % 2 == 0) ? '0' : '1';
                char leftExpected2 = (left % 2 == 0) ? '1' : '0';

                if (s[left % n] != leftExpected1) diff1--;
                if (s[left % n] != leftExpected2) diff2--;

                left++;
            }

            // When window size is exactly n, check answer
            if (right - left + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};