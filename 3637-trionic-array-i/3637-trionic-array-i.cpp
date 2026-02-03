class Solution {
public:


    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;  // Minimum length to form 3 segments

        int i = 1;

        // Phase 1: strictly increasing
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }

        // Need at least one increase and cannot end here
        if (i == 1 || i == n) return false;

        // Phase 2: strictly decreasing
        int decStart = i;
        while (i < n && nums[i] < nums[i - 1]) {
            i++;
        }

        // Need at least one decrease and cannot end here
        if (i == decStart || i == n) return false;

        // Phase 3: strictly increasing
        int inc2Start = i;
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }

        // Need at least one increase in phase 3 and must reach end
        return (i == n && inc2Start < n);
    }

};