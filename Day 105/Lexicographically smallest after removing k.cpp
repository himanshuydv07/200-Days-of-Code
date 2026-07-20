class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n = s.size();

        // Check if n is a power of 2
        if ((n & (n - 1)) == 0)
            k /= 2;
        else
            k *= 2;

        if (k >= n) return "-1";

        int remove = k;
        string st;

        for (char c : s) {
            while (!st.empty() && remove > 0 && st.back() > c) {
                st.pop_back();
                remove--;
            }
            st.push_back(c);
        }

        while (remove > 0) {
            st.pop_back();
            remove--;
        }

        if (st.empty()) return "-1";
        return st;
    }
};
