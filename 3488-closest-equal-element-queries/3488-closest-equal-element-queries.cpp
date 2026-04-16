#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> pos;
        pos.reserve(n * 2);

        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }

        vector<int> best(n, -1);

        for (auto& [val, v] : pos) {
            int sz = v.size();
            if (sz == 1) continue;

            for (int i = 0; i < sz; ++i) {
                int cur = v[i];
                int prev = v[(i - 1 + sz) % sz];
                int next = v[(i + 1) % sz];

                int d1 = abs(cur - prev);
                d1 = min(d1, n - d1);

                int d2 = abs(cur - next);
                d2 = min(d2, n - d2);

                best[cur] = min(d1, d2);
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (int q : queries) {
            ans.push_back(best[q]);
        }

        return ans;
    }
};