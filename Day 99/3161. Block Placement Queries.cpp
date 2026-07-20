class Solution {
public:
    vector<int> tree;
    int n;

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) update(node << 1, l, mid, idx, val);
        else update(node << 1 | 1, mid + 1, r, idx, val);
        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) >> 1;
        return max(
            query(node << 1, l, mid, ql, qr),
            query(node << 1 | 1, mid + 1, r, ql, qr)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 0;
        for (auto &q : queries) mx = max(mx, q[1]);

        n = mx + 2;
        tree.assign(4 * n, 0);

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(mx + 1);

        update(1, 0, n - 1, mx + 1, mx + 1);

        vector<bool> ans;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto rIt = obstacles.upper_bound(x);
                int r = *rIt;
                int l = *prev(rIt);

                update(1, 0, n - 1, r, r - x);
                update(1, 0, n - 1, x, x - l);

                obstacles.insert(x);
            }
            else {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                int prevObs = *prev(it);

                int best = query(1, 0, n - 1, 0, prevObs);
                best = max(best, x - prevObs);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};
