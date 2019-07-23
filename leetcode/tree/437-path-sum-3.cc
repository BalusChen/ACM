
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
