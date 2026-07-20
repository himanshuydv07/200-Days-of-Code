
class Solution {
public:
    static const int MOD = 1000000007;

    int countStrings(int n, int k) {
        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(k + 1, vector<long long>(2, 0))
        );

        dp[1][0][0] = 1;
        dp[1][0][1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {

                // End with 0
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;

                // End with 1 after 0
                dp[i][j][1] = dp[i - 1][j][0];

                // End with 1 after 1 (creates one new adjacent pair)
                if (j > 0) {
                    dp[i][j][1] =
                        (dp[i][j][1] + dp[i - 1][j - 1][1]) % MOD;
                }
            }
        }

        return (dp[n][k][0] + dp[n][k][1]) % MOD;
    }
};
