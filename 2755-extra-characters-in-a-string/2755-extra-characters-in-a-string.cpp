class Solution {
public:
    int recurExtraChar(string& s, unordered_map<string, int>& mp, vector<int>& dp, int idx) {
        if (idx >= s.length()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        string str = "";
        int ans = s.size();
        for (int currIdx = idx; currIdx < s.length(); currIdx++) {
            str.push_back(s[currIdx]);
            int count = (mp.count(str) ? 0 : str.size()) + recurExtraChar(s, mp, dp, currIdx + 1);
            ans = min(count, ans);
        }
        return dp[idx] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n, -1);
        unordered_map<string, int> mp;
        for (string & word: dictionary) {
            mp[word]++;
        }
        return recurExtraChar(s, mp, dp, 0);

        
    }
};