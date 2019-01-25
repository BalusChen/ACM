#include "../include/make-tree.h"

// 我对这种在树中找一条链路的题目总是不太会(这一题的答案也是我从discuss中找的)
// 还需要多加练习、理解
class Solution {
    public:
        int longestUnivaluePath(TreeNode *root) {
            if (root != nullptr)
                longestUnivaluePathHelper(root, -1);
            return len_;
        }

        int longestUnivaluePathHelper(TreeNode *curr, int val) {
            if (curr == nullptr)
                return 0;
            int L = longestUnivaluePathHelper(curr->left, curr->val),
                R = longestUnivaluePathHelper(curr->right, curr->val),
                count = 0;
            len_ = std::max(len_, L+R);
            if (curr->val == val)
                count = 1 + std::max(L, R);
            return count;
        }
    private:
        int len_ = 0;
};
