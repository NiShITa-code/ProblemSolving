class Solution {
public:
    // For each index i:
    // returns how many characters from i match prefix
    vector<int> computePrefixMatchLength(const string &s) {
        int n = s.size();
        vector<int> matchLen(n);
        int left = 0, right = 0;

        for (int i = 1; i < n; i++) {
            if (i <= right) {
                matchLen[i] = min(matchLen[i - left], right - i + 1);
            }

            while (i + matchLen[i] < n && s[matchLen[i]] == s[i + matchLen[i]]) {
                matchLen[i]++;
            }

            if (i + matchLen[i] - 1 > right) {
                left = i;
                right = i + matchLen[i] - 1;
            }
        }

        matchLen[0] = n;
        return matchLen;
    }

    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int totalLen = n + m - 1;

        string result(totalLen, '?');

        // Prefix matching info for str2
        vector<int> prefixMatch = computePrefixMatchLength(str2);
        // Step 1: Apply all 'T' constraints
        int lastTStart = -m;

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') continue;

            int overlap = max(0, lastTStart + m - i);

            // Check if overlap is valid
            if (overlap > 0 && prefixMatch[m - overlap] < overlap) {
                return "";
            }

            // Fill remaining characters
            for (int j = overlap; j < m; j++) {
                result[i + j] = str2[j];
            }

            lastTStart = i;
        }

        // Step 2: Fill remaining '?' with 'a'
        // Track last editable position
        vector<int> lastEditable(totalLen);
        int lastFree = -1;

        for (int i = 0; i < totalLen; i++) {
            if (result[i] == '?') {
                result[i] = 'a';
                lastFree = i;
            }
            lastEditable[i] = lastFree;
        }

        // Step 3: Handle 'F' constraint

        // Build prefix match info for (str2 + result)
        vector<int> combinedMatch = computePrefixMatchLength(str2 + result);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') continue;

            // If substring equals str2 → need to break
            if (combinedMatch[m + i] < m) continue;

            int changePos = lastEditable[i + m - 1];

            if (changePos < i) {
                return ""; // cannot modify
            }

            // Change this position to break match
            result[changePos] = 'b';

            // Skip forward
            i = changePos;
        }

        return result;
    }
};