class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        vector<bool> dp(k, false);

        for (int x : arr) {
            vector<bool> ndp = dp;

            // Start a new subset with only x
            ndp[x % k] = true;

            // Extend previous subsets
            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    ndp[(r + x) % k] = true;
                }
            }

            dp = ndp;

            if (dp[0]) return true;
        }

        return false;
    }
};
