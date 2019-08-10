
/*
 * Copyright (C) Jianyong Chen
 */


#include "../leetcode/include/make-tree.h"


class Solution {
	public:
		TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
			if (pre.size() == 0) {
				return nullptr;
			}

			pre_ = pre;
			vin_ = vin;

			return aux(0, pre.size()-1, 0, vin.size()-1);
		}

		TreeNode *aux(int p_b, int p_e, int i_b, int i_e) {
			int        root_val, idx;
			TreeNode  *root;

			if (p_b > p_e || i_b > i_e) {
				return nullptr;
			}


			root_val = pre_[p_b];
			root = new TreeNode(root_val);

			// 找出 root 节点值在中序序列中的位置(下标索引)
			// NOTE: 注意find(s, e, val)是在[s, e)中查找
			idx = std::find(vin_.begin()+i_b, vin_.begin()+i_e+1, root_val) - vin_.begin();

			// idx-i_b表示左子树中的元素个数
			root->left = aux(p_b+1, p_b+idx-i_b, i_b, idx-1);
			root->right = aux(p_b+idx-i_b+1, p_e, idx+1, i_e);

			return root;
		}

	private:
		std::vector<int>  pre_;
		std::vector<int>  vin_;
};
