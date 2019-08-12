
/*
 * Copyright (C) Jianyong Chen
 */


#include "../leetcode/include/make-tree.h"


class Solution {
    public:
        /*
         * NOTE: empty **tree** IS NOT sub-struct of any other
         *       but empty **node** is sub-struct of any other
         *       so we introduce a level of indirection
         */
        bool HasSubtree(TreeNode *root1, TreeNode *root2) {
            if (root2 == nullptr) {
                return false;
            }

            return HasSubtree2(root1, root2);
        }

        bool HasSubtree2(TreeNode *root1, TreeNode *root2) {
            if (root2 == nullptr) {
                return true;
            }

            if (root1 == nullptr) {
                return false;
            }

            if (root1->val == root2->val) {
                return (HasSubtree2(root1->left, root2->left)
                        && HasSubtree2(root1->right, root2->right))
                    || HasSubtree2(root1->left, root2)
                    || HasSubtree2(root1->right, root2);
            }

            return HasSubtree2(root1->left, root2)
                || HasSubtree2(root1->right, root2);
        }
};
