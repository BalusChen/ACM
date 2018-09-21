#ifndef MAKE_TREE_H__
#define MAKE_TREE_H__

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x),
          left(nullptr),
          right(nullptr) {  }
};

TreeNode *MakeTree(const std::vector<int> &ivec) {
    if (ivec.empty())
        return nullptr;

    TreeNode *rootp = new TreeNode(ivec[0]), *p;
    std::queue<TreeNode*> q;
    int i = 1, j, sz;
    q.push(rootp);

    while (i < ivec.size()) {
        sz = q.size();
        for (j = 0; j < sz; ++j) {
            p = q.front();
            q.pop();
            if (i < ivec.size()) {
                if (ivec[i] !=  INT_MAX) {
                    p->left = new TreeNode(ivec[i]);
                    q.push(p->left);
                }
                ++i;
            } else break;
            if (i < ivec.size()) {
                if (ivec[i] != INT_MAX) {
                    p->right = new TreeNode(ivec[i]);
                    q.push(p->right);
                }
                ++i;
            } else break;
        }
    }

    return rootp;
}

void PrintTree(TreeNode *root) {
    if (root == nullptr)
        return;
    std::queue<TreeNode*> q;
    TreeNode *p = nullptr;
    int sz;

    q.push(root);
    while (!q.empty()) {
        sz = q.size();
        for (int i = 0; i < sz; ++i) {
            p = q.front();
            q.pop();
            if (p != nullptr) {
                std::cout << p->val << "  ";
                q.push(p->left);
                q.push(p->right);
            } else {
                std::cout << "#" << "  ";
            }
        }
        std::cout << '\n';
    }
}

#endif /* MAKE_TREE_H__ */

