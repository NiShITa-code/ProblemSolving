class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.size();

        vector<int> dp(27, 0); // 26 letters + 26 = "not used"
        int total = 0;

        for (int i = 0; i < n - 1; i++) {
            int cur = word[i] - 'A';
            int next = word[i + 1] - 'A';

            vector<int> newdp = dp;

            for (int j = 0; j <= 26; j++) {
                int d1 = dist(cur, next);                  // main finger move
                int d2 = dist(j == 26 ? -1 : j, next);     // other finger move

                newdp[cur] = max(newdp[cur], dp[j] + d1 - d2);
            }

            dp = newdp;
            total += dist(cur, next);
        }

        int maxSave = 0;
        for (int j = 0; j <= 26; j++) {
            maxSave = max(maxSave, dp[j]);
        }

        return total - maxSave;
    }
};