class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
         int n = s.size();
    vector<int> count(3, 0);

    int left = 0;
    int ans = INT_MAX;

    for(int right = 0; right < n; right++) {
        count[s[right] - '0']++;

        // while substring contains 0,1,2
        while(count[0] > 0 && count[1] > 0 && count[2] > 0) {
            ans = min(ans, right - left + 1);
            count[s[left] - '0']--;
            left++;
        }
    }

    return ans == INT_MAX ? -1 : ans;
    }
};
