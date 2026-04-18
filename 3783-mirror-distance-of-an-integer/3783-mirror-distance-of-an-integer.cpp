class Solution {
public:
    int reverseNum(int n) {
        int revNum = 0;
        while(n > 0) {
            int x = n % 10;
            revNum = revNum* 10 + x;
            n = n / 10;
        }
        return revNum;
    }
    int mirrorDistance(int n) {
        int revNum = reverseNum(n);
        return abs(revNum - n);
    }
};