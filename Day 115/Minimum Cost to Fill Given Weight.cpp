class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        // code here
      const long long INF = 1e18;

        vector<long long> dp(w + 1, INF);
        dp[0] = 0;

        int n = cost.size();

        for (int wt = 1; wt <= n; wt++) {
            if (cost[wt - 1] == -1) continue;

            for (int cur = wt; cur <= w; cur++) {
                if (dp[cur - wt] != INF) {
                    dp[cur] = min(dp[cur],
                                  dp[cur - wt] + cost[wt - 1]);
                }
            }
        }

        return (dp[w] == INF ? -1 : (int)dp[w]);  
    }
};
