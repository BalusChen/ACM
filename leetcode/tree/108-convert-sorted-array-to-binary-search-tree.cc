#include "../include/make-tree.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return aux(nums, 0, nums.size()-1);
    }

    TreeNode *
    aux(std::vector<int> &nums, int lo, int hi)
    {
        int        mid;
        TreeNode  *root;

        if (lo > hi) {
            return nullptr;
        }

        mid = lo + (hi - lo) / 2;
        root = new TreeNode(nums[mid]);

        root->left  = aux(nums, lo, mid-1);
        root->right = aux(nums, mid+1, hi);

        return root;
    }
};
