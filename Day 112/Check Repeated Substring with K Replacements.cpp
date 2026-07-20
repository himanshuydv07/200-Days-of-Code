class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        int n = s.size();

        // String must be divisible into blocks of length k
        if (n % k != 0) return false;

        int blocks = n / k;

        unordered_map<string, int> freq;
        int mx = 0;

        for (int i = 0; i < n; i += k) {
            string block = s.substr(i, k);
            mx = max(mx, ++freq[block]);
        }

        // Already all equal, or only one block differs
        return mx >= blocks - 1;
    }
};
