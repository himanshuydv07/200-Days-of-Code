class Solution {
public:
    struct Node {
        int next[26];
        int idx;
        int len;

        Node() {
            memset(next, -1, sizeof(next));
            idx = -1;
            len = INT_MAX;
        }
    };

    vector<Node> trie;

    void update(int node, int index, int length) {
        if (length < trie[node].len ||
            (length == trie[node].len && index < trie[node].idx)) {
            trie[node].len = length;
            trie[node].idx = index;
        }
    }

    void insert(string &word, int index) {
        int node = 0;
        int n = word.size();

        update(node, index, n);

        for (int i = n - 1; i >= 0; --i) {
            int c = word[i] - 'a';

            if (trie[node].next[c] == -1) {
                trie[node].next[c] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].next[c];
            update(node, index, n);
        }
    }

    int search(string &word) {
        int node = 0;
        int ans = trie[0].idx;

        for (int i = word.size() - 1; i >= 0; --i) {
            int c = word[i] - 'a';

            if (trie[node].next[c] == -1)
                break;

            node = trie[node].next[c];
            ans = trie[node].idx;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.reserve(500000 + 5);
        trie.emplace_back(); // root

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (auto &q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};
