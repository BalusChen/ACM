#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) :
        val(_val), left(nullptr), right(nullptr) {  }
};

class Solution {
    public:
        bool findTarget(TreeNode *root, int k) {
            if (root == nullptr)
                return false;

            InorderTraverse(root);
            int i = 0, j = data.size()-1;
            for (; i != j; ) {
                if (data[i]+data[j] == k)
                    return true;
                else if (data[i]+data[j] < k)
                    ++i;
                else
                    --j;
            }

            return false;
        }

        void InorderTraverse(TreeNode *root) {
            if (root == nullptr)
                return;
            InorderTraverse(root->left);
            data.push_back(root->val);
            InorderTraverse(root->right);
        }
        std::vector<int> data;
};
