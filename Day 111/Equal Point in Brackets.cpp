class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n = s.size();

        int rightClose = 0;
        for (char ch : s) {
            if (ch == ')')
                rightClose++;
        }

        int leftOpen = 0;

        for (int i = 0; i < n; i++) {
            if (leftOpen == rightClose)
                return i;

            if (s[i] == '(')
                leftOpen++;
            else
                rightClose--;
        }

        if (leftOpen == rightClose)
            return n;

        return -1;
    }
};
