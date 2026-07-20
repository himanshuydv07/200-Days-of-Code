class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_set<long long> st;
        
        for (long long x : arr) {
            
            // Special case when target is 0
            if (target == 0) {
                if (x == 0 || st.count(0))
                    return true;
            }
            else {
                // Check if target is divisible by x
                if (x != 0 && target % x == 0) {
                    long long need = target / x;
                    
                    if (st.count(need))
                        return true;
                }
            }
            
            st.insert(x);
        }
        
        return false;
    }
};
