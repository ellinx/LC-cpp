#include "../Solutions.hpp"

using namespace std;

/***************** Validate Binary Search Tree *****************/
/*
 Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

    2
   / \
  1   3

Binary tree [2,1,3], return true.

Example 2:

    1
   / \
  2   3

Binary tree [1,2,3], return false. 
*/
bool DFS(TreeNode* root, TreeNode* &pre);

bool Solutions::isValidBST(TreeNode* root) {
	TreeNode* pre = NULL; //store previous value there is problem(like the very first node value is INT_MIN).
	return DFS(root, pre);
}

bool DFS(TreeNode* root, TreeNode* &pre) {
	if (root == NULL) return true;

	if (!DFS(root->left,pre)) return false;

	if (pre==NULL) {
		pre = root;
	} else {
		if (pre->val<root->val) {
			pre = root;
		} else return false;
	}

	if (!DFS(root->right,pre)) return false;

	return true;
}
