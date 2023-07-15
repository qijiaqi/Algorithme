struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return BST(root, LONG_MIN, LONG_MAX);
        // Inorder : [5,4,6,null,null,3,7] -> 3 < 5
        // if (!root) return true;
        // if (root -> left && root -> left -> val >= root -> val) return false;
        // if (root -> right && root -> right -> val <= root -> val) return false;
        // return isValidBST(root -> left) && isValidBST(root -> right);
    }
    bool BST (TreeNode* root, long min, long max) {
        // Inorder
        if (!root) return true;
        if (root -> left) {
            if (root -> left -> val >= root -> val || root -> left -> val <= min) return false;
        }
        if (root -> right) {
            if(root -> right -> val <= root -> val || root -> right -> val >= max) return false;
        }
        return BST(root -> left, min, root -> val) && BST(root -> right, root -> val, max);
    }
};