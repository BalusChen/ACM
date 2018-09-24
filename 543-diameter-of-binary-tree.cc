#include "include/make-tree.h"

/* diameter = max(subtree-diameter, left+right) */
class Solution {
    public:
        int diameterOfBinaryTree(TreeNode *root) {
            return 0;
        }

        int GetMaxDepth(TreeNode *root) {
            if (root == nullptr) return 0;
            int left = GetMaxDepth(root->left);
            int right = GetMaxDepth(root->right);
            max = std::max(max, left+right);
            return std::max(left, right) + 1;
        }

        int max = 0;
};
