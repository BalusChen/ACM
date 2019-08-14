
/*
 * Copyright (C) Jianyong Chen
 */


#include "../leetcode/include/make-tree.h"


class Solution
{
    public:
        TreeNode* Convert(TreeNode *root)
        {
            return ConvertRight(root);
        }

        TreeNode *ConvertLeft(TreeNode *root) {
            if (root == nullptr) {
                return nullptr;
            }

            aux(root);

            while (root->right != nullptr) {
                root = root->right;
            }

            return root;    /* tail of list */
        }

        TreeNode *ConvertRight(TreeNode *root) {
            if (root == nullptr) {
                return nullptr;
            }

            aux(root);

            while (root->left != nullptr) {
                root = root->left;
            }

            return root;    /* head of list */
        }

        void aux(TreeNode *root) {
            TreeNode  *left_tail, *right_begin;

            left_tail = ConvertLeft(root->left);
            if (left_tail != nullptr) {
                left_tail->right = root;
            }
            root->left = left_tail;

            right_begin = ConvertRight(root->right);
            if (right_begin != nullptr) {
                right_begin->left = root;
            }
            root->right = right_begin;
        }
};
