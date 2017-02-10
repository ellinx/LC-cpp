#include "Solutions.hpp"
using namespace std;

/************* Invert Binary Tree ****************/
/*
 Invert a binary tree.

      4
    /   \
   2     7
  / \   / \
 1   3 6   9

 to
      4
    /   \
   7     2
  / \   / \
 9   6 3   1

*/

TreeNode* Solutions::invertTree(TreeNode* root) {
    if (root == NULL) {
        return root;
    }

    TreeNode* tmp_node = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp_node);
    return root;
}
