class Solution {
public:
    const int MOD = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        set<int> s;
        unordered_map<int, int> dp;
        for (int num: arr) {
            s.insert(num);
            dp[num] = 1;
        }

        for (int i: arr) {
            for (int j: arr) {
                if (j > sqrt(i)) {
                    break;
                }
                if (i % j == 0 && s.find(i/j) != s.end()) {
                    long long mul = (long long) dp[j] * dp[i/j];
                    if (i / j == j) {
                        dp[i] =(dp[i] + mul) % MOD;
                    } else {
                        dp[i] = (dp[i] + mul * 2) % MOD;
                    }
                }
            }
        }

        int res = 0;
        for (auto pair: dp) {
            res = (res + pair.second) % MOD;
        }
      
        return res;

    }
};