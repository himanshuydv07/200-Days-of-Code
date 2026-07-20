class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        if (x == 1) 
        return y == 1;

    // Keep dividing y by x
    while (y % x == 0) {
        y /= x;
    }

    // If y becomes 1, then it's power of x
    return y == 1;
    }
};
