#include <iostream>
#include <vector>
#include <list>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<std::vector<int>>
zigzagLevelOrder(TreeNode* root) {
    enum {
        kLeft2Right = 0,
        kRight2Left = 1,
    };

    std::vector<std::vector<int>>  ret;
    std::list<TreeNode *>          l;
    int                            level_sz, direction;
    TreeNode                       *cur;

    if (root == nullptr) {
        return ret;
    }

    direction = kLeft2Right;
    l.push_back(root);
    while (!l.empty()) {
        std::vector<int> level;
        level_sz = l.size();
        for (int i = 0; i < level_sz; i++) {
            if (direction == kLeft2Right) {
                cur = l.front();
                l.pop_front();
            } else {
                cur = l.back();
                l.pop_back();
            }

            level.push_back(cur->val);
            if (direction == kLeft2Right) {
                // store child to the back of list `l` from left to right
                if (cur->left != nullptr) l.push_back(cur->left);
                if (cur->right != nullptr) l.push_back(cur->right);
            } else {
                // store child to the front of list `l` from right to left
                if (cur->right != nullptr) l.push_front(cur->right);
                if (cur->left != nullptr) l.push_front(cur->left);
            }
        }

        ret.push_back(level);
        direction = !direction;     // make a turn
    }

    return ret;
}
