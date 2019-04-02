#include "../include/make-tree.h"
#include <stack>


std::vector<int>
postorderTraversal(TreeNode* root)
{
    std::stack<TreeNode*>  nstack;
    std::vector<int>       postorder;

    if (root == nullptr) {
        return std::vector<int>();
    }

    for ( ;; ) {
        if (root != nullptr) {
            nstack.push(root);
            root = root->left;

        } else {
            root = nstack.top()->right;

            if (root == nullptr) {
                root = nstack.top();
                postorder.push_back(root->val);

                nstack.pop();
                while (!nstack.empty() && nstack.top()->right == root) {
                    root = nstack.top();
                    nstack.pop();
                    postorder.push_back(root->val);
                }
                if (nstack.empty()) {
                    break;
                }

                root = nstack.top()->right;
            }
        }
    }

    return postorder;
}
