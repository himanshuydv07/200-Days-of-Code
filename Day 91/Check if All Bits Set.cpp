class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if (n == 0) return false;
        
        // Numbers with all bits set satisfy:
        // n & (n + 1) == 0
        return (n & (n + 1)) == 0;
    }
};
