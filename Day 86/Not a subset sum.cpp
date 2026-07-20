class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        sort(arr.begin(), arr.end());

        long long res = 1;

        for (int x : arr) {
            // If current element is greater than res,
            // then res cannot be formed
            if (x > res)
                break;

            // Extend the range of representable sums
            res += x;
        }

        return res;
    }
};
