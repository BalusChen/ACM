
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-tree.h"
#include <unordered_map>


class Solution {
    public:
        int rob(TreeNode* root) {
            int  max;

            max = 0;
            dp[nullptr] = std::vector<int>{0, 0};
            dfs(max, root);

            return max;
        }

        void dfs(int &max, TreeNode *root) {
            std::vector<int>  profits;

            if (root == nullptr) {
                return;
            }

            /* profits[0]: robbed; profits[1]: not robbed */

            profits.resize(2);
            if (root->left == nullptr && root->right == nullptr) {
                profits[0] = root->val;
                profits[1] = 0;
                dp[root] = profits;

            } else {
                dfs(max, root->left);
                dfs(max, root->right);

                std::vector<int> &left_profits = dp[root->left];
                std::vector<int> &right_profits = dp[root->right];
                profits[0] = left_profits[1] + right_profits[1] + root->val;
                profits[1] = std::max(left_profits[0] , left_profits[1])
                    + std::max(right_profits[0] , right_profits[1]);
            }

            dp[root] = profits;
            max = std::max(std::max(profits[0], profits[1]), max);
        }

    private:
        std::unordered_map<TreeNode *, std::vector<int>>  dp;
};
