class Solution {
  public:
    int longestSubstr(string& s, int k) {
        vector<int> freq(26, 0);
    
    int left = 0;
    int maxFreq = 0;
    int ans = 0;

    for (int right = 0; right < s.size(); right++) {
        freq[s[right] - 'A']++;
        
        maxFreq = max(maxFreq, freq[s[right] - 'A']);
        
        // if invalid window shrink
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }
        
        ans = max(ans, right - left + 1);
    }
    
    return ans;
    }
};
