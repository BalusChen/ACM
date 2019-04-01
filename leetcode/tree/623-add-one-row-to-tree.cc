#include "../include/make-tree.h"

TreeNode*
addOneRow(TreeNode* root, int v, int d) {
    int                    level_sz, level;
    TreeNode              *left, *right, *cur;
    std::queue<TreeNode*>  q;


    if (d == 1) {
        cur = new TreeNode(v);
        cur->left = root;
        return cur;
    }

    if (root == nullptr) {
        return nullptr;
    }

    level = 1;
    q.push(root);
    while (level != d-1) {
        level_sz = q.size();
        for (int i = 0; i < level_sz; i++) {
            cur = q.front();
            q.pop();
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        level++;
    }

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        left = cur->left;
        right = cur->right;
        cur->left = new TreeNode(v);
        cur->right = new TreeNode(v);
        cur->left->left = left;
        cur->right->right = right;
    }

    return root;
}
