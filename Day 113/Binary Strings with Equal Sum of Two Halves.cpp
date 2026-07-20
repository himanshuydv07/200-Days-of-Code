
class Solution {
public:
    static const int MOD = 1000000007;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int computeValue(int n) {
        int N = 2 * n;

        vector<long long> fact(N + 1), invFact(N + 1);

        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[N] = modPow(fact[N], MOD - 2);

        for (int i = N; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }

        long long ans = fact[N];
        ans = ans * invFact[n] % MOD;
        ans = ans * invFact[n] % MOD;

        return (int)ans;
    }
};
