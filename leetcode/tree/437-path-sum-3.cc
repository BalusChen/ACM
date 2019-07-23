
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-tree.h"

class Solution {
    public:
        int pathSum(TreeNode* root, int sum) {
            std::vector<int>  sums;

            origin_sum = sum;
            sums.push_back(sum);
            aux(root, sums);
            return count;
        }

        void aux(TreeNode *root, std::vector<int> &sums) {
            std::vector<int>  l_sums, r_sums;

            if (root == nullptr) {
                return;
            }

            for (auto &sum : sums) {
                if (sum == root->val) {
                    ++count;
                }

                sum -= root->val;
            }

            sums.push_back(origin_sum);
            l_sums = sums;
            r_sums = sums;

            aux(root->left, l_sums);
            aux(root->right, r_sums);
        }

    private:
        int  count = 0;
        int  origin_sum;
};

class Solution2
{
    public:
        int pathSum(TreeNode *root, int sum) {
            std::vector<int>  pre_sums;

            pre_sums.push_back(0);
            return dfs(root, pre_sums, sum);
        }

        int dfs(TreeNode *root, std::vector<int> &pre_sums, int target_sum) {
            int  cur_sum, count;

            if (root == nullptr) {
                return 0;
            }

            count = 0;
            cur_sum = root->val + pre_sums.back();
            for (auto pre_sum : pre_sums) {
                if (cur_sum - pre_sum == target_sum) {
                    ++count;
                }
            }

            pre_sums.push_back(cur_sum);
            count += dfs(root->left, pre_sums, target_sum);
            count += dfs(root->right, pre_sums, target_sum);
            pre_sums.pop_back();

            return count;
        }
};
