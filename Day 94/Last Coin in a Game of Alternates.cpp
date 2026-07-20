class Solution {
  public:
    int coin(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;

        while (l < r) {
            if (arr[l] >= arr[r])
                l++;
            else
                r--;
        }

        return arr[l];
    }
};
