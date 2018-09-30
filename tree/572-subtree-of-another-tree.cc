#include "../include/make-tree.h"

class Solution {
    public:
        bool isSubtree(TreeNode *s, TreeNode *t) {
            if (s == nullptr)
                return false;
            return IsSameTree(s, t) ||
                   isSubtree(s->left, t) ||
                   isSubtree(s->right, t);
        }

        bool IsSameTree(TreeNode *root1, TreeNode *root2) {
            if (root1 == nullptr && root2 == nullptr)
                return true;
            if (root1 != nullptr && root2 != nullptr)
                return root1->val == root2->val &&
                       IsSameTree(root1->left, root2->left) &&
                       IsSameTree(root1->right, root2->right);
            return false;
        }
};
