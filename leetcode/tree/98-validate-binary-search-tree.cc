#include "../include/make-tree.h"
#include <stack>

bool isValidBST(TreeNode *root) {
    int                     pre;
    bool                    is_pre_leftmost;
    std::stack<TreeNode *>  s;

    if (root == nullptr) {
        return true;
    }

    // 最左节点 前面没有访问过的节点(它就是第一个被访问的)
    is_pre_leftmost = true;
    while (root != nullptr || !s.empty()) {
        // 向左一路添加下去
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }

        root = s.top();
        s.pop();
        // 对于非最左节点，检查其后前一个访问的节点的值的大小关系
        if (!is_pre_leftmost && root->val <= pre) {
            return false;
        }
        is_pre_leftmost = false;
        pre = root->val;    // 记住前一个访问过的结点的值
        root = root->right; // 转向右子树
    }

    return true;
}
