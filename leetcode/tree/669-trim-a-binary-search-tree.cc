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

        TreeNode *trimBST(TreeNode *root, int L, int R) {
            if (root == nullptr)
                return nullptr;

            if (root->val < L)
                root = trimBST(root->right, L, R);
            else if (root->val > R)
                root = trimBST(root->left, L, R);
            else {
                root->left = trimBST(root->left, L, R);
                root->right = trimBST(root->right, L, R);
            }
            return root;
        }

};
