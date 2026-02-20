class Solution {
public:
    string makeLargestSpecial(string s) {
         vector<string> substrings;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                count++;
            else
                count--;

            // Found a complete special substring
            if (count == 0) {
                // Recursively solve inner part
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                
                substrings.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // Sort in descending order
        sort(substrings.begin(), substrings.end(), greater<string>());

        // Combine all substrings
        string result = "";
        for (auto &sub : substrings)
            result += sub;

        return result;
        
    }
};