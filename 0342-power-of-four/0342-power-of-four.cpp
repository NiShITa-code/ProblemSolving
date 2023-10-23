class Solution {
public:
    bool isPowerOfFour(int n) {
        // power of 4 has a 1 only at odd position 
        int mask = 0x55555555;// this is a mask with bit set at odd position
        return n > 0 && (n & (n - 1)) == 0 && (n & mask) == n;
        
    }
};