class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st;
        for (int i = 0; i < nums.size(); i++) {
            char digit = nums[i];
            while(!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        if (st.empty()) {
            return "0";
        }
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();            
        }
        // Trimming the zeroes at the back
        while(result.size() > 0 && 
              result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        // Edge case
        if(result.empty()) return "0";
        
        // Return the stored result
        return result;

    }
};