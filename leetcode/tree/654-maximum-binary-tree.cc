#include "../include/make-tree.h"

class Solution {
    public:
        TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) {
            if (nums.empty())
                return nullptr;

            TreeNode *root = new TreeNode(nums[0]);
            for (int i = 1; i < nums.size(); ++i) {
                if (root->val < nums[i]) {
                    TreeNode *node = new TreeNode(nums[i]);
                    node->left = root;
                    root = node;
                } else { // no duplicates: root->val > nums[i]
                    TreeNode *node = new TreeNode(nums[i]);
                    InsertToRight(root, node);
                }
            }

            return root;
        }

        void InsertToRight(TreeNode *curr, TreeNode *x) {
            if (curr->right == nullptr) {
                curr->right = x;
            } else if (curr->right->val < x->val) {
                x->left = curr->right;
                curr->right = x;
            } else {
                InsertToRight(curr->right, x);
            }
        }
};
