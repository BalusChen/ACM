
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include//make-tree.h"


class Solution
{
    public:
        int  ret = 0;

        int sumNumber(TreeNode *root) {
            aux(root, 0);

            return ret;
        }

        void aux(TreeNode *node, int heritage) {
            if (node == nullptr) {
                return;
            }

            heritage = heritage * 10 + node->val;
            if (node->left == nullptr && node->right == nullptr) {
                ret += heritage;
            }

            aux(node->left, heritage);
            aux(node->right, heritage);
        }
};
