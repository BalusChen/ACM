#include "../include/make-tree.h"
#include <stack>

int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode *>  s;

    while (root != nullptr || !s.empty()) {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();
        if (--k == 0) {
            break;
        }
        root = root->right;
    }

    return root->val;
}
