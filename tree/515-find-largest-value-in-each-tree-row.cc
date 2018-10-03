#include "../include/make-tree.h"

class Solution {
    public:
        std::vector<int> largestValues(TreeNode *root) {
            std::vector<int> ret;
            std::queue<TreeNode*> q;

            if (root == nullptr)
                return ret;

            q.push(root);
            while (!q.empty()) {
                int sz = q.size();
                int max = INT_MIN;
                for (int i = 0; i < sz; ++i) {
                    auto front = q.front();
                    q.pop();
                    if (front->val > max)
                        max = front->val;
                    if (front->left != nullptr) q.push(front->left);
                    if (front->right != nullptr) q.push(front->right);
                }
                ret.push_back(max);
            }

            return ret;
        }
};

