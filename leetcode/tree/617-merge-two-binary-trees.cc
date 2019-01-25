#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {  }
};

TreeNode *CloneTree(TreeNode *root) {
    if (root == nullptr)
        return  nullptr;

    TreeNode *ret = new TreeNode(root->val);
    ret->left = CloneTree(root->left);
    ret->right = CloneTree(root->right);
    return ret;
}

TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr)
        return CloneTree(t2);
    else if (t2 == nullptr)
        return CloneTree(t1);
    else  {
        TreeNode *ret = new TreeNode(t1->val + t2->val);
        ret->left = mergeTrees(t1->left, t2->left);
        ret->right = mergeTrees(t1->right, t2->right);
        return ret;
    }
}
