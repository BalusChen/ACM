#include "../include/make-tree.h"
#include <queue>

class Solution {
    public:
        int minDepth(TreeNode *root) {
            std::queue<TreeNode*> q;
            int depth  = 0;

            if (root == nullptr)
                return 0;

            q.push(root);
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; ++i) {
                    auto node = q.front();
                    q.pop();
                    if (IsLeaf(node))
                        return depth+1;
                    else {
                        if (node->left != nullptr) q.push(node->left);
                        if (node->right != nullptr) q.push(node->right);
                    }
                }
                ++depth;
            }
            return depth;
        }

        bool IsLeaf(TreeNode *node) {
            return node->left == nullptr && node->right == nullptr;
        }
};

// 别人家的答案🤢🤢
// 我开始也想的是用这种递归方法
// 但是不知道递增高度
int minDepth(TreeNode *root) {
    if (root == nullptr)
        return 0;
    int L = minDepth(root->left), R = minDepth(root->right);
    // 这里需要理解
    // 如果最小者为0，说明有一个子节点为NULL，不是叶子节点，所以应该选择另外一个
    return 1 + (std::min(L, R) ? std::min(L, R) : std::max(L, R));
}
