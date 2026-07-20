class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        
        int n = a.size();

        vector<pair<int,int>> tasks;

        // Store difference and index
        for (int i = 0; i < n; i++) {
            tasks.push_back({abs(a[i] - b[i]), i});
        }

        // Sort by maximum difference descending
        sort(tasks.begin(), tasks.end(), greater<pair<int,int>>());

        long long profit = 0;

        for (auto &t : tasks) {
            int idx = t.second;

            // Prefer machine with higher profit
            if ((a[idx] >= b[idx] && x > 0) || y == 0) {
                profit += a[idx];
                x--;
            } else {
                profit += b[idx];
                y--;
            }
        }

        return profit;
    }
};
