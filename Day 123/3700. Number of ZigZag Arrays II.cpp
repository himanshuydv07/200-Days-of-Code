#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const long long MOD = 1000000007LL;

    struct Matrix {
        int n;
        vector<vector<long long>> a;

        Matrix(int n_, bool ident = false) : n(n_) {
            a.assign(n, vector<long long>(n, 0));
            if (ident) {
                for (int i = 0; i < n; i++) a[i][i] = 1;
            }
        }
    };

    Matrix multiply(const Matrix &A, const Matrix &B) {
        int n = A.n;
        Matrix C(n);

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!A.a[i][k]) continue;
                long long cur = A.a[i][k];

                for (int j = 0; j < n; j++) {
                    if (!B.a[k][j]) continue;
                    C.a[i][j] = (C.a[i][j] + cur * B.a[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.n;
        Matrix res(n, true);

        while (exp > 0) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int sz = 2 * m; // [U(0..m-1), D(m..2m-1)]

        Matrix T(sz);

        // U_next[y] += D[x] for x < y
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < y; x++) {
                T.a[m + x][y] = 1;
            }
        }

        // D_next[y] += U[x] for x > y
        for (int y = 0; y < m; y++) {
            for (int x = y + 1; x < m; x++) {
                T.a[x][m + y] = 1;
            }
        }

        vector<long long> base(sz, 0);

        // Length = 2 initialization
        for (int v = 0; v < m; v++) {
            base[v] = v;             // U[v] = count of previous values < v
            base[m + v] = m - 1 - v; // D[v] = count of previous values > v
        }

        Matrix P = power(T, n - 2);

        vector<long long> state(sz, 0);

        for (int j = 0; j < sz; j++) {
            long long val = 0;
            for (int k = 0; k < sz; k++) {
                val = (val + base[k] * P.a[k][j]) % MOD;
            }
            state[j] = val;
        }

        long long ans = 0;
        for (long long x : state) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};
