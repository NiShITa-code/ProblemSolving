class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int firstLargest = INT_MIN;
        int secondLargest = INT_MIN;
        int thirdLargest = INT_MIN;
        int firstSmallest = INT_MAX;
        int secondSmallest = INT_MAX;
        for (int num: nums) {
            if (num >= firstLargest) {
                thirdLargest = secondLargest;
                secondLargest = firstLargest;
                firstLargest = num;
            } else if (num >= secondLargest) {
                thirdLargest = secondLargest;
                secondLargest = num;
            } else if (num >= thirdLargest) {
                thirdLargest = num;
            }

            if (num < firstSmallest) {
                secondSmallest = firstSmallest;
                firstSmallest = num;
            } else if(num < secondSmallest) {
                secondSmallest = num;
            }
        }
        return max(thirdLargest*secondLargest*firstLargest, firstLargest*firstSmallest*secondSmallest);
    }
};