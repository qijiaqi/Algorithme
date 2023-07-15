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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Levelorder
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            while (size --) {
                TreeNode* node = que.front();
                vec.push_back(node -> val);
                que.pop();
                if (node -> left) que.push(node -> left);
                if (node -> right) que.push(node -> right);
            }
            res.push_back(vec);
        }
        return res;
    }
};