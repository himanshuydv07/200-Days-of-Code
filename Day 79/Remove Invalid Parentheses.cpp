
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isValid(string &s) {
        int bal = 0;
        
        for(char c : s) {
            if(c == '(') bal++;
            else if(c == ')') {
                if(bal == 0) return false;
                bal--;
            }
        }
        
        return bal == 0;
    }
    
    vector<string> validParenthesis(string s) {
        
        vector<string> ans;
        unordered_set<string> vis;
        queue<string> q;
        
        q.push(s);
        vis.insert(s);
        
        bool found = false;
        
        while(!q.empty()) {
            
            string cur = q.front();
            q.pop();
            
            if(isValid(cur)) {
                ans.push_back(cur);
                found = true;
            }
            
            // Stop generating deeper levels
            if(found) continue;
            
            for(int i = 0; i < cur.size(); i++) {
                
                if(cur[i] != '(' && cur[i] != ')')
                    continue;
                
                string nxt = cur.substr(0, i) + cur.substr(i + 1);
                
                if(!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};
