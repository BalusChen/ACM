
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-tree.h"

class Solution
{
    public:
        std::vector<int> rightSideView(TreeNode *root) {
            int                     i, level_size;
            TreeNode               *front;
            std::vector<int>        view;
            std::queue<TreeNode *>  que;

            if (root == nullptr) {
                return view;
            }

            que.push(root);
            while (!que.empty()) {
                level_size = que.size();
                for (i = 0; i < level_size; i++) {
                    front = que.front();
                    que.pop();

                    if (front->left != nullptr) {
                        que.push(front->left);
                    }

                    if (front->right != nullptr) {
                        que.push(front->right);
                    }
                }

                view.push_back(front->val);
            }

            return view;
        }
};
