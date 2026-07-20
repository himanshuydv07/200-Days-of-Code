class Solution {
  public:
    int maxSubstring(string &s) {
        int maxSum = -1;
        int currSum = 0;

        for (char ch : s) {
            int val = (ch == '0') ? 1 : -1;

            currSum = max(val, currSum + val);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
