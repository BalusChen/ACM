#include "../include/make-tree.h"

class Solution {
    public:
        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode* q) {
            // 如果对于root，p，q在root的两棵子树上，那么LCA就是root
            // 否则就向下走到p，q所在的子树(此时他们两个在同一棵树上)
            // 知道他们两个在不同的子树上，或者其中一个是另一个的子结点
            while ((root->val - p->val) * (root->val - q->val) > 0)
                root = (p->val < root->val) ? root->left : root->right;
            return root;
        }
};
