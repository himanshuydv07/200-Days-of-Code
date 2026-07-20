class Solution {
  public:
    int optimalKeys(int n) {
        // code here
        if (n <= 6) return n;

        vector<long long> dp(n + 1);

        // Base cases
        for (int i = 1; i <= 6; i++) {
            dp[i] = i;
        }

        // Compute maximum A's for each key press count
        for (int i = 7; i <= n; i++) {
            dp[i] = 0;

            // Try all possible breakpoints
            for (int j = i - 3; j >= 1; j--) {
                // After j presses:
                // Ctrl+A, Ctrl+C take 2 presses
                // Remaining (i-j-2) presses are Ctrl+V
                long long curr = dp[j] * (i - j - 1);

                dp[i] = max(dp[i], curr);
            }
        }

        return dp[n];
    }
};
