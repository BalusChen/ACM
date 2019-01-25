#include "../include/make-tree.h"

class Solution {
    public:
        TreeNode *pruneTree(TreeNode *root) {
            if (root == nullptr)
                return nullptr;

            pruneTree(root->left);
            pruneTree(root->right);
            if (IsLeaf(root->left) && root->left->val == 0)
                root->left = nullptr;
            if (IsLeaf(root->right) && root->right->val == 0)
                root->right = nullptr;
            return root;
        }

        bool IsLeaf(TreeNode *root) {
            return (root != nullptr && root->left == nullptr && root->right == nullptr);
        }
};
