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
    TreeNode* create(vector<int>& nums, int i, int j) {
        if (i > j) return nullptr;
        int m = i + (j - i) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node -> left = create(nums, i, m-1);
        node -> right = create(nums, m+1, j);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums, 0, nums.size()-1);
    }
};