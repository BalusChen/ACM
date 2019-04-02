#include "../include/make-tree.h"

class Solution {
private:
    std::vector<int> pre_;
    std::vector<int> in_;

public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        pre_ = preorder;
        in_  = inorder;

        return aux(0, pre_.size()-1, 0, in_.size()-1);
    }

    // postorder_begin, postorder_end, inorder_begin, inorder_end
    TreeNode *aux(int p_b, int p_e, int i_b, int i_e) {
        TreeNode    *root;
        int          idx;

        if (p_b > p_e || i_b > i_e) {
            return nullptr;
        }

        root = new TreeNode(pre_[p_b]); // last element of preorder sequence is the root

        // find the index of the root in the inorder sequence
        // to make a partition into left subtree and right subtree
        idx = std::find(in_.begin()+i_b, in_.begin()+i_e, pre_[p_b]) - in_.begin();

        // build left and right subtree recursively
        root->left = aux(p_b+1, p_b+idx-i_b, i_b, idx-1);
        root->right = aux(p_b+idx-i_b+1, p_e, idx+1, i_e);

        return root;
    }
};
