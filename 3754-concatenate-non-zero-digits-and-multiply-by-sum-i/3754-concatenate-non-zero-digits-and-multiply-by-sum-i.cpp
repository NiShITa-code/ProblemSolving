class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0, pow = 1;
        while(n > 0) {
            int digit =  n % 10;
            sum += digit;
            if (digit > 0) {
                x += digit * pow;
                pow *= 10;
            }
            n = n / 10;
        }
        return x*sum;
    }
};