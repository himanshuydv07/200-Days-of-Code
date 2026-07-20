class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        int flips = __builtin_popcount(pos - 1);

        return (flips % 2 == 0) ? "Engineer" : "Doctor";
    }
};
