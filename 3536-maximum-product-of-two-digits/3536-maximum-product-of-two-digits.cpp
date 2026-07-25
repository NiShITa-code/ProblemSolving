class Solution {
public:
    int maxProduct(int n) {
        int firstMax = 0, secondMax = 0;
        while(n > 0) {
            int num = n % 10;
            if (num > firstMax) {
                secondMax = firstMax;
                firstMax = num;
            } else if (num > secondMax) {
                secondMax = num;
            }
            n = n / 10;
        }
        return firstMax*secondMax;  
    }
};