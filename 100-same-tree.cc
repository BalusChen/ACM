struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) :
        val(_val), left(nullptr), right(nullptr) {  }
};

class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p == nullptr && q == nullptr)
                return true;
            if (p != nullptr && q != nullptr) {
                if (p->val == q->val) {
                    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
                }
                return false;
            }
            return false;
        }
};
