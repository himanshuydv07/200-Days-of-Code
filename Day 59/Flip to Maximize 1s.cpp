class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
    
    int totalOnes = 0;
    for(int x : arr)
        if(x == 1) totalOnes++;

    int maxGain = 0, currGain = 0;

    for(int i = 0; i < n; i++) {
        int val = (arr[i] == 0) ? 1 : -1;

        currGain = max(val, currGain + val);
        maxGain = max(maxGain, currGain);
    }

    return totalOnes + maxGain;
    }
};
