class Solution {
public:
     long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int need = k - 1;
        long long sumSmall = 0;

        multiset<int> small, large;

        auto add = [&](int x) {
            small.insert(x);
            sumSmall += x;

            if (small.size() > need) {
                auto it = prev(small.end()); // largest in small
                int val = *it;
                small.erase(it);
                sumSmall -= val;
                large.insert(val);
            }
        };

        auto remove = [&](int x) {
            if (small.find(x) != small.end()) {
                small.erase(small.find(x));
                sumSmall -= x;

                if (!large.empty()) {
                    int val = *large.begin();
                    large.erase(large.begin());
                    small.insert(val);
                    sumSmall += val;
                }
            } else {
                large.erase(large.find(x));
            }
        };

        long long ans = LLONG_MAX;
        int L = 1;

        for (int R = 1; R < n; R++) {
            add(nums[R]);

            if (R - L + 1 > dist + 1) {
                remove(nums[L]);
                L++;
            }

            if (R - L + 1 >= need) {
                ans = min(ans, sumSmall);
            }
        }

        return ans + nums[0];

    }
};