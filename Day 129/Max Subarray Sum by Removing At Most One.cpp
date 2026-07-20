

class Solution {
public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();

        vector<int> fw(n), bw(n);

        // Maximum subarray ending at i
        fw[0] = arr[0];
        int ans = arr[0];
        for (int i = 1; i < n; i++) {
            fw[i] = max(arr[i], fw[i - 1] + arr[i]);
            ans = max(ans, fw[i]);
        }

        // Maximum subarray starting at i
        bw[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            bw[i] = max(arr[i], bw[i + 1] + arr[i]);
        }

        // Delete one element
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, fw[i - 1] + bw[i + 1]);
        }

        return ans;
    }
};
