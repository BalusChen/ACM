
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-tree.h"
#include <stack>

/* iterative version */

class Solution
{
    public:
        void flatten(TreeNode *root) {
            aux(root);
        }

        TreeNode *aux(TreeNode *root) {
            TreeNode  *right, *p;

            if (root == nullptr) {
                return root;
            }

            right = root->right;
            root->right = aux(root->left);
            root->left = nullptr;

            p = root;
            while (p->right != nullptr) {
                p = p->right;
            }

            p->right = aux(right);

            return root;
        }
};

/* recursive version */

class Solution2 {
    public:
        void flatten(TreeNode *root) {
            TreeNode  *p;

            if (root == nullptr) {
                return;
            }

            flatten(root->left);
            flatten(root->right);

            std::swap(root->left, root->right);

            p = root;
            while (p->right != nullptr) {
                p = p->right;
            }
            p->right = root->left;
            root->left = nullptr;
        }
};


int
main(int argc, char **argv)
{
    Solution2          ans;
    TreeNode           dummy_head(0), *root;
    std::vector<int>   elts;

    elts = { 1, 2, 5, 3, 4, INT_MAX, 6 };
    root = MakeTree(elts);
    ans.flatten(root);
    PrintTree(root);

    printf("\n");
    root = &dummy_head;
    root->right = new TreeNode(0); root = root->right;
    root->right = new TreeNode(1); root = root->right;
    root->right = new TreeNode(2); root = root->right;
    root->right = new TreeNode(3); root = root->right;
    root->right = new TreeNode(4);
    ans.flatten(dummy_head.right);
    PrintTree(dummy_head.right);
    delete dummy_head.right;

    printf("\n");
    root = &dummy_head;
    root->left = new TreeNode(7); root = root->left;
    root->left = new TreeNode(6); root = root->left;
    root->left = new TreeNode(5); root = root->left;
    root->left = new TreeNode(4); root = root->left;
    root->left = new TreeNode(3); root = root->left;
    root->left = new TreeNode(2); root = root->left;
    root->left = new TreeNode(1); root = root->left;
    root->left = new TreeNode(0);
    ans.flatten(dummy_head.right);
    PrintTree(dummy_head.right);
    delete dummy_head.left;

    printf("\n");
    elts = { 1, INT_MAX, 2, 3 };
    root = MakeTree(elts);
    ans.flatten(root);
    PrintTree(root);

    return 0;
}
