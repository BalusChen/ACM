#include "../include/make-tree.h"

class Solution {
private:
    std::vector<int>  in_;
    std::vector<int>  post_;

public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        in_   = inorder;
        post_ = postorder;

        return aux(0, in_.size()-1, 0, post_.size()-1);
    }

    TreeNode *
    aux(int i_b, int i_e, int p_b, int p_e)
    {
        int        idx;
        TreeNode  *root;

        if (i_b > i_e || p_b > p_e) {
            return nullptr;
        }

        // last element of postorder sequence is the root
        root = new TreeNode(post_[p_e]);
        idx = std::find(in_.begin()+i_b, in_.begin()+i_e, post_[p_e]) - in_.begin();

        root->left = aux(i_b, idx-1, p_b, p_b+idx-i_b-1);
        root->right = aux(idx+1, i_e, p_b+idx-i_b, p_e-1);

        return root;
    }
};
