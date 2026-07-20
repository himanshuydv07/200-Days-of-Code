class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
         int n = arr.size();

    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[i] < arr[left])
            return false;

        // Check right child
        if (right < n && arr[i] < arr[right])
            return false;
    }

    return true;
    }
};
