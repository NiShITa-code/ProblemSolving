class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0, n = nums.size();

        // Phase 1: increasing
        while (i < n - 1 && nums[i + 1] > nums[i]) i++;
        int p = i;

        if (p == 0) return false;  // no increase

        // Phase 2: decreasing
        int decStart = i;
        while (i < n - 1 && nums[i + 1] < nums[i]) i++;
        int q = i;

        if (q == decStart) return false;  // no decrease

        // Phase 3: increasing
        int inc2Start = i;
        while (i < n - 1 && nums[i + 1] > nums[i]) i++;

        if (i == inc2Start) return false; // no final increase

        return i == n - 1;
    }
};


