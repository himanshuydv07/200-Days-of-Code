/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
      bool isIdentical(Node* a, Node* b) {
        if (!a && !b)
            return true;

        if (!a || !b)
            return false;

        return (a->data == b->data) &&
               isIdentical(a->left, b->left) &&
               isIdentical(a->right, b->right);
    }

    // Check if root2 is subtree of root1
    bool isSubTree(Node* root1, Node* root2) {

        // Empty tree is always subtree
        if (!root2)
            return true;

        // If main tree becomes empty
        if (!root1)
            return false;

        // If trees match from current node
        if (isIdentical(root1, root2))
            return true;

        // Otherwise search in left and right subtree
        return isSubTree(root1->left, root2) ||
               isSubTree(root1->right, root2);
    }
};
