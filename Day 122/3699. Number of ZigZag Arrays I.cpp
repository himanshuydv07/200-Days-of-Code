class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 2, 0), down(m + 2, 0);
        vector<int> nup(m + 2, 0), ndown(m + 2, 0);
        vector<int> pref(m + 2, 0), suff(m + 3, 0);

        // length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {
            pref[0] = 0;
            for (int i = 1; i <= m; i++) {
                pref[i] = pref[i - 1] + down[i];
                if (pref[i] >= MOD) pref[i] -= MOD;
            }

            suff[m + 1] = 0;
            for (int i = m; i >= 1; i--) {
                suff[i] = suff[i + 1] + up[i];
                if (suff[i] >= MOD) suff[i] -= MOD;
            }

            for (int x = 1; x <= m; x++) {
                nup[x] = pref[x - 1];
                ndown[x] = suff[x + 1];
            }

            swap(up, nup);
            swap(down, ndown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) {
            ans += up[v];
            ans += down[v];
        }

        return (int)(ans % MOD);
    }
};
