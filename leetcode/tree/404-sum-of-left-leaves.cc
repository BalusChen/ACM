
/*
 * Copyright (C) Jianyong Chen
 */

#include "../include/make-tree.h"

class Solution {
    public:
        int sumOfLeftLeaves(TreeNode *root) {
            int sum = 0;

            if (root == nullptr) {
                return 0;
            }

            if (root->left != nullptr && IsLeaf(root->left)) {
                sum += root->left->val;

            } else {
                sum += sumOfLeftLeaves(root->left);
            }

            if (root->right != nullptr) {
                sum += sumOfLeftLeaves(root->right);
            }

            return sum;
        }

        bool IsLeaf(TreeNode *root) {
            return (root->left == nullptr) && (root->right == nullptr);
        }
};
