
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-tree.h"

class Solution
{
    public:
        int  sum = 0;
        int countNodes(TreeNode *root) {
            aux(root);

            return sum;
        }

        bool aux(TreeNode *node) {
            bool  left, right;

            if (node == nullptr) {
                return true;
            }

            if (node->left == nullptr && node->right != nullptr) {
                return false;
            }

            left = aux(node->left);
            right = aux(node->right);
            if (left && right) {
                sum++;
            }

            return left && right;
        }
};
