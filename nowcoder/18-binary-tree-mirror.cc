
/*
 * Copyright (C) Jianyong Chen
 */


#include "../leetcode/include/make-tree.h"


class Solution {
    public:
        void Mirror(TreeNode *root) {
            if (root == nullptr) {
                return;
            }

            std::swap(root->left, root->right);
            Mirror(root->left);
            Mirror(root->right);
        }
};
