class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
         int n = arr.size();
    long long totalSum = 0;

    for (int bit = 0; bit < 32; bit++) {
        long long cnt1 = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] & (1 << bit)) {
                cnt1++;
            }
        }

        long long cnt0 = n - cnt1;

        totalSum += cnt1 * cnt0 * (1LL << bit);
    }

    return totalSum;
        
    }
};
