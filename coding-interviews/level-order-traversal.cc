#include "../leetcode/include/make-tree.h"

class Solution {
public:
    std::vector<std::vector<int> > Print(TreeNode* pRoot) {
            std::vector<std::vector<int>>  sequence;
            std::vector<int>  level;
            int               level_sz;
            std::queue<TreeNode *> q;
            TreeNode               *front;

            if (pRoot == nullptr) {
                return std::vector<std::vector<int>> ();
            }

            q.push(pRoot);
            while (!q.empty()) {
                level_sz = q.size();
                level.reserve(level_sz);
                for (int i = 0; i < level_sz; i++) {
                    front = q.front();
                    q.pop();
                    level.push_back(front->val);
                    if (front->left != nullptr) {
                        q.push(front->left);
                    }
                    if (front->right != nullptr) {
                        q.push(front->right);
                    }
                }
                sequence.push_back(level);
                level.clear();
            }

            return sequence;
        }
};
