#include "../include/make-tree.h"

class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if (root == nullptr) return true;
            return IsSame(root->left, root->right);
        }

        bool IsSame(TreeNode *left, TreeNode *right) {
            if (left == nullptr && right == nullptr)
                return true;
            if (left != nullptr && right != nullptr && left->val == right->val)
                return IsSame(left->left, right->right) &&
                       IsSame(left->right, right->left);
            return false;
        }
};
