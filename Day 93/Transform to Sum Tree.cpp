/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  int solve(Node* root) {
        if (root == NULL)
            return 0;

        // Store original value
        int oldValue = root->data;

        // Recursively get subtree sums
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        // Update current node value
        root->data = leftSum + rightSum;

        // Return total sum including original node value
        return root->data + oldValue;
    }
    void toSumTree(Node *root) {
        // code here
                solve(root);

    }
};
