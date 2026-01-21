class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // for storing answer
        vector<int> nge(10001, -1);
        stack<int> st;
        
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> result;
        for (int num: nums1) {
            result.push_back(nge[num]);
        }
        return result;
    }
};