class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> pg(n), ng(n), ps(n), ns(n);
        stack<int> st;

        // Previous Greater (<=)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            pg[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater (<)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            ng[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Smaller (>=)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller (>)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            ns[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long countMax = 1LL * (i - pg[i]) * (ng[i] - i);
            long long countMin = 1LL * (i - ps[i]) * (ns[i] - i);
            total += (countMax - countMin) * nums[i];
        }

        return total;
    }

    
};


