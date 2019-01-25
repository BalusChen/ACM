#include "include/make-tree.h"
#include <queue>
#include <list>

class Solution {
    public:
        std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
            if (root == nullptr)
                return ret;
            std::queue<TreeNode*> q;
            q.push(root);
            std::list<std::vector<int>> ret2;
            while (!q.empty()) {
                int sz = q.size();
                std::vector<int> level;
                for (int i = 0; i < sz; ++i) {
                    TreeNode *top = q.front();
                    q.pop();
                    level.push_back(top->val);
                    if (top->left != nullptr) q.push(top->left);
                    if (top->right != nullptr) q.push(top->right);
                }
                ret2.push_front(level);
            }
            ret = std::vector<std::vector<int>> (ret2.begin(), ret2.end());
            return ret;
        }

        std::vector<std::vector<int>> ret;
};
