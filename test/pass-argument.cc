#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) :
        val(_val), left(nullptr), right(nullptr) {  }
};

void Change(TreeNode *ptr) {
    ptr->val = 7;
}

int
main(void) {
    TreeNode *ptr = new TreeNode(37);
    Change(ptr);
    std::cout << ptr->val << std::endl;

    return 0;
}
