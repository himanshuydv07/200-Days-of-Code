class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> left(n, vector<int>(m, 0));
        vector<vector<int>> right(n, vector<int>(m, 0));
        vector<vector<int>> up(n, vector<int>(m, 0));
        vector<vector<int>> down(n, vector<int>(m, 0));

        // Any 1 to the left
        for (int i = 0; i < n; i++) {
            int seen = 0;
            for (int j = 0; j < m; j++) {
                left[i][j] = seen;
                if (mat[i][j] == 1) seen = 1;
            }
        }

        // Any 1 to the right
        for (int i = 0; i < n; i++) {
            int seen = 0;
            for (int j = m - 1; j >= 0; j--) {
                right[i][j] = seen;
                if (mat[i][j] == 1) seen = 1;
            }
        }

        // Any 1 above
        for (int j = 0; j < m; j++) {
            int seen = 0;
            for (int i = 0; i < n; i++) {
                up[i][j] = seen;
                if (mat[i][j] == 1) seen = 1;
            }
        }

        // Any 1 below
        for (int j = 0; j < m; j++) {
            int seen = 0;
            for (int i = n - 1; i >= 0; i--) {
                down[i][j] = seen;
                if (mat[i][j] == 1) seen = 1;
            }
        }

        int totalCoverage = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    totalCoverage += left[i][j];
                    totalCoverage += right[i][j];
                    totalCoverage += up[i][j];
                    totalCoverage += down[i][j];
                }
            }
        }

        return totalCoverage;
    }
};
