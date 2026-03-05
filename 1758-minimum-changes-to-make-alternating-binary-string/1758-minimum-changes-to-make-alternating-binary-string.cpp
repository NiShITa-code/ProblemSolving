class Solution {
public:
    int minOperations(string s) {
        // two possiblieties string eitehr starts with 0 or with 1
        int minStartWithZero = 0;
        int minStartWithOne = 0;
        for (int i = 0; i < s.length(); i++) {
            char sZero = (i % 2 == 0) ? '0' : '1';
            char sOne = (i % 2 == 0) ? '1' : '0';
            if (sZero != s[i]) {
                minStartWithZero++;    
            }
            if (sOne != s[i]) {
                minStartWithOne++;    
            }
        }
        return min(minStartWithOne,minStartWithZero);

    
    }
};