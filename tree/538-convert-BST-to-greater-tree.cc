struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) :
        val(_val), left(nullptr), right(nullptr) {  }
};

class Solution {
    public:
        TreeNode *convertBST(TreeNode *root) {
            if (root != nullptr) {
                convertBST(root->right);
                sum += root->val;
                root->val = sum;
                convertBST(root->left);
            }

            return root;
        }

        int sum = 0;
};
