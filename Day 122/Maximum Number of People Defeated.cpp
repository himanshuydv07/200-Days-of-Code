class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        long long lo = 0, hi = 10000; // sufficient for p <= 3e8
        long long ans = 0;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            long long sum = mid * (mid + 1) * (2 * mid + 1) / 6;

            if (sum <= p) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return (int)ans;
    }
};
