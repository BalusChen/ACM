
/*
 * Copyright (C) Jianyong Chen
 */


#include "../leetcode/include/make-tree.h"


class Solution {
    public:
        void Mirror(TreeNode *root) {
            TreeNode  *tmp;

            if (root == nullptr) {
                return;
            }

            tmp = root->left;
            root->left = root->right;
            root->right = tmp;

            Mirror(root->left);
            Mirror(root->right);
        }
};
