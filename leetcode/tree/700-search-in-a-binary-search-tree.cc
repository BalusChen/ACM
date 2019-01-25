struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) :
        val(_val), left(nullptr), right(nullptr) {  }
};

class Solution {
    public:
        TreeNode *searchBST(TreeNode *root, int val) {
            if (root == nullptr)
                return nullptr;
            else if (val < root->val)
                return searchBST(root->left, val);
            else if (val > root->val)
                return searchBST(root->right, val);
            else
                return root;
        }
};
