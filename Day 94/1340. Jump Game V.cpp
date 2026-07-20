class Solution {
public:
    int n, D;
    vector<int> dp;

    int dfs(int i, vector<int>& arr) {
        if (dp[i] != -1) return dp[i];

        int ans = 1; // count current index

        // check right
        for (int j = i + 1; j <= min(n - 1, i + D); j++) {
            if (arr[j] >= arr[i]) break;
            ans = max(ans, 1 + dfs(j, arr));
        }

        // check left
        for (int j = i - 1; j >= max(0, i - D); j--) {
            if (arr[j] >= arr[i]) break;
            ans = max(ans, 1 + dfs(j, arr));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        D = d;
        dp.assign(n, -1);

        int res = 1;
        for (int i = 0; i < n; i++) {
            res = max(res, dfs(i, arr));
        }

        return res;
    }
};
