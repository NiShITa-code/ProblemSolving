class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> C(n, 0);
        int commonEle = 0;
        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                commonEle++;
            }
            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                commonEle++;
            }
            cout << commonEle;
            C[i] = commonEle;
        }
        return C;
    }
};