class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLength = 1;

        // --------------------------------------------------
        // CASE 1: Only one distinct character
        // --------------------------------------------------
        // Just find the longest continuous streak
        int streak = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                streak++;
            } else {
                streak = 1;
            }
            maxLength = max(maxLength, streak);
        }

        // --------------------------------------------------
        // CASE 2: Exactly two distinct characters
        // --------------------------------------------------
        // For each pair: (a,b), (b,c), (a,c)
        vector<pair<char, char>> pairs = {
            {'a','b'}, {'b','c'}, {'a','c'}
        };

        for (auto [ch1, ch2] : pairs) {

            unordered_map<int,int> firstIndexOfDiff;

            int diff = 0;               // imbalance between ch1 and ch2
            firstIndexOfDiff[0] = -1;   // diff 0 before starting

            for (int i = 0; i < n; i++) {

                if (s[i] == ch1) {
                    diff++;             // one more ch1
                }
                else if (s[i] == ch2) {
                    diff--;             // one more ch2
                }
                else {
                    // third character breaks this region
                    // so we restart tracking from here
                    firstIndexOfDiff.clear();
                    firstIndexOfDiff[0] = i;
                    diff = 0;
                    continue;
                }

                // If we have seen this diff before,
                // substring between those indices has equal ch1 and ch2
                if (firstIndexOfDiff.count(diff)) {
                    maxLength = max(maxLength, i - firstIndexOfDiff[diff]);
                } else {
                    firstIndexOfDiff[diff] = i;
                }
            }
        }

        // --------------------------------------------------
        // CASE 3: All three distinct characters
        // --------------------------------------------------
        int countA = 0, countB = 0, countC = 0;

        // Store first time we see a state (A-B, A-C)
        map<pair<int,int>, int> firstStateIndex;
        firstStateIndex[{0,0}] = -1;

        for (int i = 0; i < n; i++) {

            if (s[i] == 'a') countA++;
            else if (s[i] == 'b') countB++;
            else countC++;

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            pair<int,int> state = {diffAB, diffAC};

            // If we have seen this state before,
            // substring between them has equal A, B, C
            if (firstStateIndex.count(state)) {
                maxLength = max(maxLength, i - firstStateIndex[state]);
            } else {
                firstStateIndex[state] = i;
            }
        }

        return maxLength;
    }
};

        
    
