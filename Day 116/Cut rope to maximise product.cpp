class Solution {
  public:
    int maxProduct(int n) {
        // code here
        if (n <= 3) return n - 1;

        long long ans = 1;

        while (n > 4) {
            ans *= 3;
            n -= 3;
        }

        ans *= n;
        return (int)ans;
    }
};
