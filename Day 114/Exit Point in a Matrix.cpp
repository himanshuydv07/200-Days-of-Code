class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        int i = 0, j = 0;
        int dir = 0; // 0=Right, 1=Down, 2=Left, 3=Up

        while (i >= 0 && i < n && j >= 0 && j < m) {
            if (mat[i][j] == 1) {
                dir = (dir + 1) % 4;
                mat[i][j] = 0;
            }

            if (dir == 0)      j++; // Right
            else if (dir == 1) i++; // Down
            else if (dir == 2) j--; // Left
            else               i--; // Up
        }

        // Move back to the last valid cell
        if (dir == 0)      j--;
        else if (dir == 1) i--;
        else if (dir == 2) j++;
        else               i++;

        return {i, j};
    }
};
