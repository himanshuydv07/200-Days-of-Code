class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> depth;
    vector<vector<int>> up;
    int LOG;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void dfs(int u, int p, const vector<vector<int>>& adj) {
        up[u][0] = p;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u, adj);
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j)) {
                a = up[a][j];
            }
        }

        if (a == b) return a;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, 1));

        dfs(1, 1, adj);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            int w = lca(u, v);
            long long dist = depth[u] + depth[v] - 2LL * depth[w];

            if (dist == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((int)modPow(2, dist - 1));
            }
        }

        return ans;
    }
};
