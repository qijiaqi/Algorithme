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
    // RC
    int maxDepth(TreeNode* root) {
        // Postorder
        if (!root) return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
    // IT
    int maxDepth(TreeNode* root) {
        // Levelorder
        queue<TreeNode*> que;
        if(root == nullptr) return 0;
        que.push(root);
        int max = 0;
        while(!que.empty()){
            int size = que.size();
            while (size --){
                TreeNode* node = que.front();
                que.pop();
                if(node -> left) que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
            ++ max;
        }
        return max;
    }
};