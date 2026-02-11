class Solution {
public:
    string nextTerm(string& input) {
        string result = "";
        char c = input[0];
        int freq = 1;
        for (int i = 1; i < input.length(); i++)  {
            if (input[i] != c) {
                result += to_string(freq);
                result += c;
                c = input[i];
                freq = 1;
            } else {
                freq++;
            }
        }
        result += to_string(freq);
        result += c;

        return result;
    }
    string countAndSay(int n) {
        string result = "1";
        if (n == 1) {
            return result;
        }
        for (int i = 1; i < n; i++) {
            result = nextTerm(result);
        }
        return result;
    }
};