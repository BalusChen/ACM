#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) :
        val(_val), left(nullptr), right(nullptr) {  }
};

class Solution {
    public:
        std::vector<double> averageOfLevels(TreeNode *root) {
            if (root == nullptr)
                return averages;

            std::queue<TreeNode*> q;
            TreeNode *top;
            double sum;
            int sz; // 记录每一层的节点个数

            q.push(root);
            while (!q.empty()) {
                sum = 0;
                sz = q.size();
                for (int i = 0; i < sz; ++i) {
                    top = q.front();
                    q.pop();
                    sum += top->val;
                    if (top->left != nullptr)
                        q.push(top->left);
                    if (top->right != nullptr)
                        q.push(top->right);
                }
                averages.push_back(sum / sz);
            }

            return averages;
        }

        std::vector<double> averages;
};
