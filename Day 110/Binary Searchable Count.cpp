class Solution {
public:
    int ans = 0;

    void dfs(int l, int r, long long low, long long high,
             vector<int>& arr) {
        if (l > r) return;

        int mid = (l + r) / 2;

        if (arr[mid] > low && arr[mid] < high)
            ans++;

        dfs(l, mid - 1, low, min(high, (long long)arr[mid]), arr);
        dfs(mid + 1, r, max(low, (long long)arr[mid]), high, arr);
    }

    int binarySearchable(vector<int>& arr) {
        ans = 0;
        dfs(0, (int)arr.size() - 1,
            LLONG_MIN, LLONG_MAX, arr);
        return ans;
    }
};
