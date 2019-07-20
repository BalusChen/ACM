
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-tree.h"


/*
 * 采用递归解法
 *
 * 对于树上的任意一个节点，它或者为 root，或者在左子树中，或者在右子树中，绝不可能同时。
 *
 * 所以对于 p，q 两节点，如果 root 为其中之一，则 root 就是他俩的 lca 了
 * 否则，递归地分别以左右子树为 root，求p，q 的 lca，并返回 lca，有三种情况：
 *      1. 左右返回都都不为空，说明子树都找到了，即 p，q 一边一个，说明 root 就是他俩的 lca
 *      2. 左返回值不为空，说明在他俩都在左子树上，那么左返回值为他俩的 lca
 *      2. 右返回值不为空，说明在他俩都在右子树上，那么右返回值为他俩的 lca
 */

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode  *left, *right;

            if (root == nullptr || root == p || root == q) {
                return root;
            }

            left = lowestCommonAncestor(root->left, p, q);
            right = lowestCommonAncestor(root->right, p, q);
            if (left && right) {
                return root;

            } else if (left) {
                return left;

            } else {
                return right;
            }
        }
};
