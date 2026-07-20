class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;

        for (string &word : words) {
            long long sum = 0;

            for (char c : word) {
                sum += weights[c - 'a'];
            }

            int rem = sum % 26;

            // Reverse alphabetical mapping:
            // 0 -> 'z', 1 -> 'y', ..., 25 -> 'a'
            result.push_back('z' - rem);
        }

        return result;
    }
};
