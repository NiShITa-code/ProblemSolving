class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // assume we doubled the array 
        // and array size become 2n 
        // eg 1,2,1 now is 1,2,1,1,2,1
        // now we can search fir the nge in circular maner as well because reaing ellemnts will be on rigth side
        // the index where element will be is i % n
        // start from end
        // we will store the elemnest in stack so that as we move toward left the newer places can look at backward available elments in stack
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = 2*n - 1; i >= 0; i--) {
            int index = i % n;
            while(!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }
            if (i < n) {
                if (!st.empty()) {
                    nge[i] = st.top();
                }
            }
            st.push(nums[index]);
        }
        return nge;
    }
};