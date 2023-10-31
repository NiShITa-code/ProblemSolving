class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> arr(n);
        arr[0] = pref[0];
        // if a ^ b = c then a ^ c =b
       
        for (int i = 1; i < n; i++) {
            arr[i]  = pref[i - 1]^pref[i];
        }
        return arr;
    }
};