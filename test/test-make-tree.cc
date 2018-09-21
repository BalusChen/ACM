#include "../include/make-tree.h"

int main() {
    std::vector<int> ivec { 3, 9, 20, INT_MAX, INT_MAX, 15, 7 };
    TreeNode *root = MakeTree(ivec);
    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    PrintTree(root);
    std::cout << "---------------\n";
    PrintTree(root2);
}
