
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-tree.h"


class Solution
{
    public:
        int maxPathSum(TreeNode *root) {
            aux(root);

            return max_path_sum;
        }

        int aux(TreeNode *root) {
            int  left_path_sum, right_path_sum, sum, path;

            if (root == nullptr) {
                return 0;
            }

            /*
             * 这一句：sum = root->val + left_path_sum + right_path_sum
             * 虽然表面上看求的是 root 为中间节点的路径和
             * 但是其实包括了三种情况：
             *      1. root 为路径中间节点
             *      2. root 为路径起始节点，向左走
             *      3. root 为路径起始节点，向右走
             * 因为如果向左走路径和会减少的话，left_path_sum 就会等于 0，right_path_sum 同理
             * 这个可以通过下面的 return 语句看出来
             */

            left_path_sum = aux(root->left);
            right_path_sum = aux(root->right);

            sum = root->val + left_path_sum + right_path_sum;
            if (sum > max_path_sum) {
                max_path_sum = sum;
            }

            /*
             * 如果是上面的节点经过 root，那么从 root 只能往一个方向走，要么向左，要么向右
             * 我们求出左右两个方向中路径和较大的那个，如果值大于 0，那么从上面往下走的时候就需要经过 root，因为这样正数会增加路径和
             * 否则就不用经过 root 了
             */

            path = root->val + std::max(left_path_sum, right_path_sum);
            return path > 0 ? path : 0;
        }

    private:
        int  max_path_sum = INT32_MIN;
};
