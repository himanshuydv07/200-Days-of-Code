class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();
        vector<long long> bit(m + 1, 0);

        auto update = [&](int idx) {
            for (; idx <= m; idx += idx & -idx)
                bit[idx]++;
        };

        auto query = [&](int idx) {
            long long res = 0;
            for (; idx > 0; idx -= idx & -idx)
                res += bit[idx];
            return res;
        };

        int ans = 0;

        for (int p : pref) {
            int pos = lower_bound(vals.begin(), vals.end(), p) - vals.begin() + 1;

            // Count previous prefix sums strictly smaller than p
            ans += query(pos - 1);

            update(pos);
        }

        return ans;
    }
};
