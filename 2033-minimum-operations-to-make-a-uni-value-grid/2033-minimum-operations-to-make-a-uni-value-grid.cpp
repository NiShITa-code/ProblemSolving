class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int result =0;
         // Flatten the grid 
        for(int i = 0;i< grid.size();i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                nums.push_back(grid[i][j]);
            }
        }   
        int length = nums.size(); 
        // Partially sorts the array so that the median element is placed at the
        // middle index
        nth_element(nums.begin(), nums.begin() + length / 2,
                    nums.end());
        int finalNum = nums[length/2];
        for(int num: nums) {
            if (num % x != finalNum % x) {
                return -1;
            }
            result += abs(finalNum- num)/x;
        }
        return result;
    }
};