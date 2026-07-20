#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        const long long INF = 1e18;

        // dp[i][j] stores the max score for the prefix up to the previous column,
        // given that h_{c-1} = i and h_c = j.
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -INF));

        // Base case: Before column 0, we assume a dummy column -1 with height 0.
        // Therefore, h_{-1} = 0.
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 0;
        }

        for (int c = 0; c < n; ++c) {
            // Prefix sums for column c to quickly calculate the score of a range
            vector<long long> pref(n + 1, 0);
            for (int r = 0; r < n; ++r) {
                pref[r + 1] = pref[r] + grid[r][c];
            }

            // Helper lambda to get sum of grid[r][c] for r in [j, M - 1]
            auto get_cost = [&](int j, int M) -> long long {
                if (M <= j) return 0;
                return pref[M] - pref[j];
            };

            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, -INF));

            // j is h_c (height of current column)
            for (int j = 0; j <= n; ++j) {
                
                // Prefix maximums for the case where i <= k  (max(i, k) = k)
                vector<long long> pref_max(n + 1, -INF);
                long long current_max = -INF;
                for (int i = 0; i <= n; ++i) {
                    current_max = max(current_max, dp[i][j]);
                    pref_max[i] = current_max;
                }

                // Suffix maximums for the case where i > k (max(i, k) = i)
                vector<long long> suff_max(n + 2, -INF);
                current_max = -INF;
                for (int i = n; i >= 0; --i) {
                    if (dp[i][j] != -INF) {
                        current_max = max(current_max, dp[i][j] + get_cost(j, i));
                    }
                    suff_max[i] = current_max;
                }

                // k is h_{c+1} (height of next column)
                for (int k = 0; k <= n; ++k) {
                    long long op1 = -INF;
                    // If i <= k, the max constraint dictates cost is bound by k
                    if (pref_max[k] != -INF) {
                        op1 = pref_max[k] + get_cost(j, k);
                    }
                    
                    // If i > k, the max constraint dictates cost is bound by i
                    long long op2 = suff_max[k + 1];

                    next_dp[j][k] = max(op1, op2);
                }
            }
            dp = next_dp;
        }

        long long ans = 0;

        for (int j = 0; j <= n; ++j) {
            ans = max(ans, dp[j][0]);
        }

        return ans;
    }
};
