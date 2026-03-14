class Solution {
public:
    string ans = "";
    int count = 0;
    void solve(int n, int k, string& curr) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                ans = curr;
            }
            return;
        }
        for (char ch : {'a', 'b', 'c'}) {
            if(!curr.empty() && curr.back() == ch) {
                continue;
            }
            curr.push_back(ch);
            solve(n, k, curr);
            curr.pop_back();

            if (!ans.empty()) return;
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        solve(n, k, curr);
        return ans;
    }
};