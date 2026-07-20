class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();

        int ones = 0;
        for (int x : arr) ones += x;

        if (ones == 0) return -1;

        int curr = 0;

        // first window
        for (int i = 0; i < ones; i++)
            curr += arr[i];

        int maxOnes = curr;

        // sliding window
        for (int i = ones; i < n; i++) {
            curr += arr[i];
            curr -= arr[i - ones];
            maxOnes = max(maxOnes, curr);
        }

        return ones - maxOnes;
    }
};
