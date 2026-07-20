class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
         int n = s.size();
        int covered = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int left = max(0, i - x);
                int right = min(n - 1, i + x);

                // gap found
                if (left > covered + 1)
                    return false;

                covered = max(covered, right);
            }
        }

        return covered >= n - 1;
    }
};
