class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
         int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        // Push all boundary 1s into queue
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }

            if (grid[i][m - 1] == 1) {
                q.push({i, m - 1});
                grid[i][m - 1] = 0;
            }
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }

            if (grid[n - 1][j] == 1) {
                q.push({n - 1, j});
                grid[n - 1][j] = 0;
            }
        }

        // Directions: up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // BFS to remove all reachable boundary-connected 1s
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    grid[nx][ny] == 1) {

                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        // Count remaining 1s
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};
