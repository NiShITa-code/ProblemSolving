class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        // Arrays to store the last two seen indices of each number.
        // Since 1 <= nums[i] <= n, we can safely use an array of size n + 1.
        std::vector<int> first_idx(n + 1, -1);
        std::vector<int> second_idx(n + 1, -1);
        
        int min_dist = -1;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            
            // If we have seen this value at least twice before, we found a good tuple
            if (first_idx[val] != -1) {
                int dist = 2 * (i - first_idx[val]);
                if (min_dist == -1 || dist < min_dist) {
                    min_dist = dist;
                }
            }
            
            // Shift the indices: the 'second' becomes the 'first', and current 'i' becomes the 'second'
            first_idx[val] = second_idx[val];
            second_idx[val] = i;
        }

        return min_dist;
    }
};