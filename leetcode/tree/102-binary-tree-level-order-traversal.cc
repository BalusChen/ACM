#include "../include/make-tree.h"

std::vector<std::vector<int>>
levelOrder(TreeNode* root) {
    int                            level_sz;
    TreeNode                      *top;
    std::queue<TreeNode *>         q;
    std::vector<std::vector<int>>  ret;

    if (root == nullptr) {
        return std::vector<std::vector<int>>();
    }

    q.push(root);
    while (!q.empty()) {
        std::vector<int> level;
        level_sz = q.size();
        for (int i = 0; i < level_sz; i++) {
            top = q.front();
            q.pop();
            level.push_back(top->val);

            if (top->left != nullptr) q.push(top->left);
            if (top->right != nullptr) q.push(top->right);
        }

        ret.push_back(level);
    }

    return ret;
}
