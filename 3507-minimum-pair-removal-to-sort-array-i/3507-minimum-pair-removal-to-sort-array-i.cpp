class Solution {
public:

    bool sorted(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        vector<int> arr(nums.begin(), nums.end());
        int minOps = 0;

        while(!sorted(arr)) {
            int minSum = INT_MAX;
            int mini = 0;
            for (int i = 0; i < arr.size() - 1; i++) {
                if (arr[i] +  arr[i + 1] < minSum) {
                    minSum = arr[i] + arr[i + 1];
                    mini = i;
                }
            }
            arr[mini] = minSum;
            arr.erase(arr.begin() + mini + 1);
            minOps++;
        }
        return minOps;
    }
};