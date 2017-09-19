/*
 * =====================================================================================
 *
 *       Filename:  merge_two_binary_trees.cpp
 *
 *    Description:  Given tow binary trees and imagine that when you put one
 *                  of then to cover another, some nodes of the two trees are
 *                  overlapped while the others are not.
 *                  You need to merge them into a new binary tree.
 *                  The merge rule is that if two nodes overlap, then sum node
 *                 dataues up as the newdataue of the merged node.
 *                  Otherwise, the NOT null node will be used as the node of new tree.
 *
 *        Version:  1.0
 *        Created:  09/18/2017 02:28:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ctom
 *   Organization:  ieach
 *
 * =====================================================================================
 */
#include <iostream>
#include <utility>
#include <memory>

struct BinaryNode
{
	int data;
	BinaryNode *left;
	BinaryNode *right;
	BinaryNode(int x) :
		data(x), left(nullptr), right(nullptr) { }
};

BinaryNode* MergeTrees(BinaryNode *t1, BinaryNode *t2){
	if(!t1) return t2;
	if(!t2) return t1;
	BinaryNode *root = new BinaryNode{t1->data + t2->data};
	root->left = MergeTrees(t1->left, t2->left);
	root->right = MergeTrees(t1->right, t2->right);
	return root;
}

int main()
{

}
