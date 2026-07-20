/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    vector<int> verticalSum(Node* root) {
        // code here
        map<int, long long> mp;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            Node* node = cur.first;
            int hd = cur.second;
            
            mp[hd] += node->data;
            
            if (node->left)
                q.push({node->left, hd - 1});
                
            if (node->right)
                q.push({node->right, hd + 1});
        }
        
        vector<int> ans;
        for (auto &it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
