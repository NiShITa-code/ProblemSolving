class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long aik = A[i][k];
                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    vector<long long> multiplyMatVec(
        const Matrix& A,
        const vector<long long>& v
    ) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0) continue;
                cur = (cur + A[i][j] * v[j]) % MOD;
            }
            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(long long n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        vector<long long> V2(S, 0);

        // U_2
        for (int i = 0; i < m; i++) {
            V2[i] = i;          // i = value-1 => count smaller values
        }

        // D_2
        for (int i = 0; i < m; i++) {
            V2[m + i] = (m - 1 - i);
        }

        Matrix T(S, vector<long long>(S, 0));

        // U <- D
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                T[i][m + j] = 1;
            }
        }

        // D <- U
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                T[m + i][j] = 1;
            }
        }

        Matrix P = power(T, n - 2);

        vector<long long> Vn = multiplyMatVec(P, V2);

        long long ans = 0;
        for (long long x : Vn) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};