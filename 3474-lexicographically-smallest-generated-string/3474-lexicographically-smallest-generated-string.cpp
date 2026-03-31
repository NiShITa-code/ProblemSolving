class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int len = n + m - 1;

        string word(len, '?');
        vector<bool> fixed(len, false);

        // Step 1: Apply 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    int pos = i + j;

                    if (word[pos] != '?' && word[pos] != str2[j]) {
                        return ""; // conflict
                    }

                    word[pos] = str2[j];
                    fixed[pos] = true;
                }
            }
        }

        // Step 2: fill remaining with 'a'
        for (int i = 0; i < len; i++) {
            if (word[i] == '?') {
                word[i] = 'a';
            }
        }

        // Step 3: handle 'F'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {

                // check if equal
                bool same = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        same = false;
                        break;
                    }
                }

                if (!same) continue;

                // need to break it
                bool changed = false;

                for (int j = m - 1; j >= 0; j--) {
                    int pos = i + j;

                    if (!fixed[pos]) {
                        // change to something different
                        word[pos] = (str2[j] == 'a') ? 'b' : 'a';
                        changed = true;
                        break;
                    }
                }

                if (!changed) return "";
            }
        }

        return word;
    }
};