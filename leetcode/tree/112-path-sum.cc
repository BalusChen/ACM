#include "../include/make-tree.h"

class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            if (root == nullptr)
                return false;
            if (!IsLeaf(root)) {
                sum -= root->val;
                return hasPathSum(root->left, sum) ||
                       hasPathSum(root->right, sum);
            } else {
                if ((sum -= root->val) == 0)
                    return true;
                else
                    return false;
            }
        }

        bool IsLeaf(TreeNode *n) {
            return n->left == nullptr && n->right == nullptr;
        }

};
