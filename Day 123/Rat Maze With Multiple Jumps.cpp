class Solution {
    int n;
    vector<vector<int>> vis; // 0 = unknown, 1 = dead end

    bool dfs(int i, int j, vector<vector<int>>& mat,
             vector<vector<int>>& ans) {

        if (i >= n || j >= n || mat[i][j] == 0)
            return false;

        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }

        if (vis[i][j])
            return false;

        ans[i][j] = 1;

        int jump = mat[i][j];

        // Smaller jumps first
        for (int k = 1; k <= jump; k++) {

            // Right preferred over Down
            if (j + k < n) {
                if (dfs(i, j + k, mat, ans))
                    return true;
            }

            if (i + k < n) {
                if (dfs(i + k, j, mat, ans))
                    return true;
            }
        }

        ans[i][j] = 0;
        vis[i][j] = 1; // mark as impossible
        return false;
    }

public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        n = mat.size();

        if (mat[0][0] == 0)
            return {{-1}};

        vector<vector<int>> ans(n, vector<int>(n, 0));
        vis.assign(n, vector<int>(n, 0));

        if (dfs(0, 0, mat, ans))
            return ans;

        return {{-1}};
    }
};
