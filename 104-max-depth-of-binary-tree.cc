#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) :
        val(_val), left(nullptr), right(nullptr) {  }
};

class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if (root == nullptr)
                return 0;
            else
                return 1+std::max(maxDepth(root->left), maxDepth(root->right));
        }
};
