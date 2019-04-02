#include <stack>
#include "../include/make-tree.h"

std::vector<int>
pre_order_traverse(TreeNode *t) {
    std::vector<int>       preorder;
    std::stack<TreeNode*>  nstack;

    if (t == nullptr) {
        return std::vector<int>();
    }

    for( ;; ) {
        if (t != nullptr){
            preorder.push_back(t->val);
            nstack.push(t);
            t = t->left;

        } else {
            if (nstack.empty()) {
                break;
            }

            t = nstack.top()->right;
            nstack.pop();
        }
    }

    return preorder;
}
