#include "../include/make-tree.h"

class Solution {
    public:
        TreeNode *insertIntoBST(TreeNode *root, int val) {
            if (root == nullptr) {
                root = new TreeNode(val);
                return root;
            }

            if (val < root->val) {
                root->left = insertIntoBST(root->left, val);
            } else if (val > root->val) {
                root->right = insertIntoBST(root->right, val);
            }

            return root;
        }

};
