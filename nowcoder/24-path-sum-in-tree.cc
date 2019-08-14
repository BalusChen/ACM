
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include "../leetcode/include/make-tree.h"


class Solution {
    private:
        template<typename T>
        using Matrix = std::vector<std::vector<T>>;

    public:
        Matrix<int> FindPath(TreeNode* root, int target) {
            Matrix<int>       pathes;
            std::vector<int>  path;

            if (root == nullptr) {
                return pathes;
            }

            aux(root, target, path, pathes);

            return pathes;
        }

    private:
        void aux(TreeNode *root, int res, std::vector<int> &prev,
                Matrix<int> &pathes)
        {
            prev.push_back(root->val);

            if (IsLeaf(root) && root->val == res) {
                pathes.push_back(prev);

            } else {

                if (root->left != nullptr) {
                    aux(root->left, res - root->val, prev, pathes);
                }

                if (root->right != nullptr) {
                    aux(root->right, res - root->val, prev, pathes);
                }
            }

            prev.pop_back();
        }

        bool IsLeaf(TreeNode *root) const {
            return root->left == nullptr && root->right == nullptr;
        }
};
