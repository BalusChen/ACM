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
        bool leafSimilar(TreeNode *root1, TreeNode *root2) {
            if (root1 == nullptr && root2 == nullptr)
                return true;

            std::vector<int> leaf_1;
            std::vector<int> leaf_2;
            GetLeaf(root1, &leaf_1);
            GetLeaf(root2, &leaf_2);
            return leaf_1 == leaf_2;
        }

        void GetLeaf(TreeNode *root, std::vector<int> *leaf) const {
            if (root == nullptr)
                return;
            if (root->left == nullptr && root->right == nullptr)
                leaf->push_back(root->val);
            GetLeaf(root->left, leaf);
            GetLeaf(root->right, leaf);
        }
};
