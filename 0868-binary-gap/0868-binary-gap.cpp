class Solution {
public:
    int binaryGap(int n) {
        int lastonei = -1;
        int maxgap = 0;
        int position = 0;
        while (n > 0) {
            if (n & 1) {  // if current bit is 1
                if (lastonei != -1) {
                    maxgap = max(maxgap, position - lastonei);
                }
                lastonei = position;
            }
            n >>= 1;      // remove last bit
            position++;;
        }

        return maxgap;    
    }
};