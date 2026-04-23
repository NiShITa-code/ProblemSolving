class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        for (auto& [val, indices] : pos) {
            int m = indices.size();
            if (m == 1) continue;

            vector<long long> prefix(m + 1, 0);
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + indices[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = 1LL * i * indices[i] - prefix[i];
                long long right = (prefix[m] - prefix[i + 1]) - 1LL * (m - i - 1) * indices[i];
                ans[indices[i]] = left + right;
            }
        }

        return ans;
    }
};