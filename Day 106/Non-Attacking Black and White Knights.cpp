class Solution {
  public:
    int numOfWays(int n, int m) {
        long long totalSquares = 1LL * n * m;
        
        // Total ways to place black and white knights
        long long totalWays = totalSquares * (totalSquares - 1);
        
        // Count attacking placements
        long long attacking = 0;
        
        if (n >= 2 && m >= 3)
            attacking += 4LL * (n - 1) * (m - 2);
            
        if (n >= 3 && m >= 2)
            attacking += 4LL * (n - 2) * (m - 1);
        
        return (int)(totalWays - attacking);
    }
};
