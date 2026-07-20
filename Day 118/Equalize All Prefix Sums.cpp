class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        // code here
        int n = arr.size();

        vector<int> ans(n);

        long long pref = 0;

        for (int i = 0; i < n; i++) {
            pref += arr[i];
            arr[i] = pref;   // reuse array for prefix sums if allowed
        }

        for (int i = 0; i < n; i++) {
            int m = i / 2;

            long long x = (m == 0 ? arr[0] : arr[m] - arr[m - 1]);

            long long sumLeft = arr[m];
            long long sumPrefix = arr[i];
            long long sumRight = sumPrefix - sumLeft;

            long long leftCost = 1LL * (m + 1) * x - sumLeft;
            long long rightCost = sumRight - 1LL * (i - m) * x;

            ans[i] = leftCost + rightCost;
        }

        return ans;
    }
};
