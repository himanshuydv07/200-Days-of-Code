class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> pos;
        for (int i = 0; i < b.size(); i++)
            pos[b[i]] = i;

        vector<int> seq;
        for (int x : a) {
            auto it = pos.find(x);
            if (it != pos.end())
                seq.push_back(it->second);
        }

        vector<int> lis;
        for (int x : seq) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }

        int lcs = lis.size();
        return (a.size() - lcs) + (b.size() - lcs);
    }
};
