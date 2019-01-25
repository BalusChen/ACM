#include "../include/make-tree.h"
#include <string>

class Solution {
    public:
        std::vector<std::string> binaryTreePaths(TreeNode *root) {
            if (root == nullptr)
                return std::vector<std::string>();

            auto left = binaryTreePaths(root->left);
            auto right = binaryTreePaths(root->right);
            std::vector<std::string> ret;
            if (left.empty() && right.empty()) {
                ret.push_back(std::to_string(root->val));
            } else {
                for (const auto &c : left)
                    ret.push_back(std::to_string(root->val) + "->" + c);
                for (const auto &c : right)
                    ret.push_back(std::to_string(root->val) + "->" + c);
            }

            return ret;
        }
};
