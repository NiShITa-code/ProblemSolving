class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return modPow(x, MOD - 2);
    }

    int concatenatedBinary(int n) {
        long long ans = 0;

        for (int len = 1; (1 << (len - 1)) <= n; ++len) {
            long long L = 1LL << (len - 1);
            long long R = min((long long)n, (1LL << len) - 1);
            if (L > n) break;

            long long k = R - L + 1;
            long long B = modPow(2, len);

            // Shift previous answer
            ans = ans * modPow(B, k) % MOD;

            // ---- Compute S1 = (B^k - 1)/(B - 1)
            long long Bk = modPow(B, k);
            long long S1 = (Bk - 1 + MOD) % MOD;
            S1 = S1 * modInverse((B - 1 + MOD) % MOD) % MOD;

            // ---- Compute sum j*B^j
            // formula:
            // (B - k*B^k + (k-1)*B^{k+1}) / (1-B)^2

            long long numerator =
                (B
                - k % MOD * Bk % MOD
                + (k - 1) % MOD * modPow(B, k + 1) % MOD
                + MOD) % MOD;

            long long denom =
                ((1 - B + MOD) % MOD) *
                ((1 - B + MOD) % MOD) % MOD;

            long long sum_jBj =
                numerator * modInverse(denom) % MOD;

            // S2 = (k-1)*S1 - sum_jBj
            long long S2 =
                ((k - 1) % MOD * S1 % MOD
                - sum_jBj + MOD) % MOD;

            // Total block contribution
            long long block =
                (L % MOD * S1 % MOD + S2) % MOD;

            ans = (ans + block) % MOD;
        }

        return ans;
    }
};