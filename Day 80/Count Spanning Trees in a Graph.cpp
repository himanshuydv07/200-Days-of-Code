
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpanTree(int n, vector<vector<int>>& edges) {
        // Special case
        if (n == 1) return 1;

        // Build Laplacian Matrix
        vector<vector<long long>> lap(n, vector<long long>(n, 0));

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v]--;
            lap[v][u]--;
        }

        // Create cofactor matrix (remove last row & column)
        vector<vector<long double>> mat(n - 1, vector<long double>(n - 1));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                mat[i][j] = lap[i][j];
            }
        }

        // Compute determinant using Gaussian Elimination
        long double det = 1.0;

        for (int i = 0; i < n - 1; i++) {
            int pivot = i;

            for (int j = i; j < n - 1; j++) {
                if (fabsl(mat[j][i]) > fabsl(mat[pivot][i])) {
                    pivot = j;
                }
            }

            if (fabsl(mat[pivot][i]) < 1e-9)
                return 0;

            if (pivot != i) {
                swap(mat[pivot], mat[i]);
                det *= -1;
            }

            det *= mat[i][i];

            for (int j = i + 1; j < n - 1; j++) {
                long double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < n - 1; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return round(det);
    }
};
