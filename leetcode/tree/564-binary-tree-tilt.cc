#include "include/make-tree.h"

class Solution {
    public:
        int findTilt(TreeNode *root) {
            if (root == nullptr || IsLeaf(root))
                return 0;
            int left = findTilt(root->left);
            int right = findTilt(root->right);
            return left + right + std::abs(SumOfTree(root->left) - SumOfTree(root->right));
        }

        bool IsLeaf(TreeNode *root) {
            return (root->left == nullptr) && (root->right == nullptr);
        }

        int SumOfTree(TreeNode *root) {
            if (root == nullptr)
                return 0;
            if (IsLeaf(root))
                return root->val;
            return root->val + SumOfTree(root->left) + SumOfTree(root->right);
        }

    private:
};
