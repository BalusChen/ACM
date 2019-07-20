#include "../include/make-tree.h"

class Solution {
    public:
        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode* q) {

            /*
             * 一个很巧妙的算法(我觉得)
             *
             * 由于 tree 是二叉搜索树，是有序的
             *
             * 所以可以将 root 节点的值和要查找的两个节点的值进行比较
             *
             *      1. 如果 root 的值在 p、q 之间，那么这两个节点一定是分别在 root 的左右
             *         此时 root 就是它俩的 lca
             *      2. 否则的话，他俩就都在 root 的某一边，往那边递归搜索即可
             */

            while ((root->val - p->val) * (root->val - q->val) > 0) {
                root = (p->val < root->val) ? root->left : root->right;
            }

            return root;
        }
};
