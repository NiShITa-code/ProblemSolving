class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = count(s.begin(), s.end(), '1');

        int maxGain = 0;
        int previousZeroLength = -1;   // -1 means "no previous zero block"

        int i = 0;

        while (i < s.size()) {
            char current = s[i];
            int start = i;

            while (i < s.size() && s[i] == current)
                i++;

            int length = i - start;

            if (current == '0') {

                // We have seen another zero block before,
                // so there is exactly one 1-block between them.
                if (previousZeroLength != -1) {
                    maxGain = max(maxGain,
                                  previousZeroLength + length);
                }

                previousZeroLength = length;
            }
        }

        return totalOnes + maxGain;
    }
};