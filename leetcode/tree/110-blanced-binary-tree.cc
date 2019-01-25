#include "../include/make-tree.h"

class Solution {
    public:
        bool isBalanced(TreeNode *root) {
            Height(root);
            return is_balanced_;
        }

        int Height(TreeNode *t) {
            if (t == nullptr) {
                return 0;
            } else {
                int L = Height(t->left), R = Height(t->right);
                if (std::abs(L - R) > 1)
                    is_balanced_ = false;
                return 1 + std::max(L, R);
            }
        }

    private:
        bool is_balanced_ = true;
};

