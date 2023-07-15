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
    int minDepth(TreeNode* root) {
        // Postorder
        if (!root) return 0;
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);
        if (left == 0 && right == 0) return 1;
        if (left == 0) return right + 1;
        if (right == 0) return left + 1;
        return min(left, right) + 1;
    }
    // IT
    int minDepth(TreeNode* root) {
        // Levelorder
        queue<TreeNode*> que;
        if(root == nullptr) return 0;
        que.push(root);
        int min = 0;
        while(!que.empty()){
            int size = que.size();
            while (size --){
                TreeNode* node = que.front();
                que.pop();
                if(!node -> left && !node -> right) return min + 1;
                if(node -> left) que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
            ++ min;
        }
        return min;
    }
};