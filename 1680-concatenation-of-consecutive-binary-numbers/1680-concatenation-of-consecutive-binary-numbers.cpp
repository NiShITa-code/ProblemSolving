class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0, len = 0, MOD = 1e9+7;
        for(int i = 1; i <= n; i++){
            if((i & (i-1)) == 0)len++;
            ans = ((ans << len) | i) % MOD;
        }
        return ans;
    }
};