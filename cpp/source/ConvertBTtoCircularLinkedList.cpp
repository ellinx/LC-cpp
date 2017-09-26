#include "../Solutions.hpp"

using namespace std;

/***************** Convert Binary Tree To Circular Linked List *****************/
/*
      4
    /   \
   2     6
  / \   / \
 1   3 5   7

 ________________________
 |                      |
 1 - 2 - 3 - 4 - 5 - 6- 7
 

*/

TreeNode* help(TreeNode* root);

void ConvertBTtoCLL(TreeNode* root) {
    if (root==NULL) return;
    
    help(root);
}

TreeNode* help(TreeNode* root) {
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    
    if (root->left == NULL && root->right == NULL) {
        root->left = root;
        root->right = root;
        return root;
    } else if (root->left != NULL && root->right == NULL) {
        left = help(root->left);
        TreeNode* lastLeft = left->left;
        left->left = root;
        root->right = left;
        lastLeft->right = root;
        root->left = lastLeft;
        return left;
    } else if (root->left == NULL && root->right != NULL) {
        right = help(root->right);
        TreeNode* lastRight = right->left;
        root->left = lastRight;
        lastRight->right = root;
        root->right = right;
        right->left = root;
        return root;
    } else {
        left = help(root->left);
        right = help(root->right);
        TreeNode* lastLeft = left->left;
        TreeNode* lastRight = right->left;
        left->left = lastRight;
        lastRight->right = left;
        lastLeft->right = root;
        root->left = lastLeft;
        root->right = right;
        right->left = root;
        return left;
    }
}
