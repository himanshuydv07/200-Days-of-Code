

class Solution {
public:
    vector<int> ans;

    void generate(int start, int len, int n, long long num) {
        if (len == n) {
            ans.push_back((int)num);
            return;
        }

        for (int d = start; d <= 9; d++) {
            generate(d + 1, len + 1, n, num * 10 + d);
        }
    }

    vector<int> increasingNumbers(int n) {
        ans.clear();

        if (n == 1) {
            for (int i = 0; i <= 9; i++)
                ans.push_back(i);
            return ans;
        }

        if (n > 10) return {};

        for (int first = 1; first <= 9; first++) {
            generate(first + 1, 1, n, first);
        }

        return ans;
    }
};
