class Solution {
public:
    static int findSetBits(int n) {
        int setBits = 0;
        while(n) {
            setBits++;
            n = n & n - 1;
        }
        return setBits;
    }
    static bool comparator(int a, int b) {
        if (findSetBits(a) == findSetBits(b)) {
            return a < b;
        }
        return findSetBits(a) < findSetBits(b);
    }
    vector<int> sortByBits(vector<int>& arr) {
       int setBits = 0;
       sort(arr.begin(), arr.end(), comparator);
       return arr;
    }
};