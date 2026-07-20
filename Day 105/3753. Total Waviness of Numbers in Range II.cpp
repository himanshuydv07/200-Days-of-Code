#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[20][2][3][10][10];
    bool vis[20][2][3][10][10];

    Node dfs(int pos, bool started, int lenState,
             int last2, int last1, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][lenState][last2][last1]) {
            return dp[pos][started][lenState][last2][last1];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        Node res{0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started) {
                if (d == 0) {
                    Node nxt = dfs(pos + 1, false, 0, 0, 0, ntight);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                } else {
                    Node nxt = dfs(pos + 1, true, 1, 0, d, ntight);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                }
            } else {
                if (lenState == 1) {
                    Node nxt = dfs(pos + 1, true, 2, last1, d, ntight);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                } else {
                    int add = 0;

                    if ((last1 > last2 && last1 > d) ||
                        (last1 < last2 && last1 < d))
                        add = 1;

                    Node nxt = dfs(pos + 1, true, 2, last1, d, ntight);

                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav + 1LL * add * nxt.cnt;
                }
            }
        }

        if (!tight) {
            vis[pos][started][lenState][last2][last1] = true;
            dp[pos][started][lenState][last2][last1] = res;
        }

        return res;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, false, 0, 0, 0, true).wav;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
