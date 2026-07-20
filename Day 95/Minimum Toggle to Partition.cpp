class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> ones(n + 1, 0);
        vector<int> zeros(n + 1, 0);
        
        // ones[i] = number of 1s in arr[0...i-1]
        for (int i = 0; i < n; i++) {
            ones[i + 1] = ones[i] + (arr[i] == 1);
        }
        
        // zeros[i] = number of 0s in arr[i...n-1]
        for (int i = n - 1; i >= 0; i--) {
            zeros[i] = zeros[i + 1] + (arr[i] == 0);
        }
        
        int ans = n;
        
        // Partition at i:
        // left [0...i-1] should be 0 → toggle all 1s
        // right [i...n-1] should be 1 → toggle all 0s
        for (int i = 0; i <= n; i++) {
            ans = min(ans, ones[i] + zeros[i]);
        }
        
        return ans;
    }
};
