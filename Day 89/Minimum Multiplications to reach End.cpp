class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        vector<int> dist(1000, 1e9);
        queue<pair<int,int>> q;
        
        dist[start] = 0;
        q.push({start, 0});
        
        while(!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(node == end) return steps;
            
            for(int x : arr) {
                int newNum = (node * x) % 1000;
                
                if(steps + 1 < dist[newNum]) {
                    dist[newNum] = steps + 1;
                    q.push({newNum, steps + 1});
                }
            }
        }
        
        return -1;
        
    }
};
