
class Solution {
public:
    int dp[105][905];
    int prefix[105];
    string str;
    int n;

    // sum of digits from l to r
    int getSum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int solve(int idx, int prevSum) {
        if (idx == n) return 1;

        if (dp[idx][prevSum] != -1)
            return dp[idx][prevSum];

        int ans = 0;

        for (int i = idx; i < n; i++) {
            int currSum = getSum(idx, i);

            if (currSum >= prevSum) {
                ans += solve(i + 1, currSum);
            }
        }

        return dp[idx][prevSum] = ans;
    }

    int validGroups(string s) {
        str = s;
        n = s.size();

        memset(dp, -1, sizeof(dp));
        memset(prefix, 0, sizeof(prefix));

        // prefix sum of digits
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (s[i] - '0');
        }

        return solve(0, 0);
    }
};
