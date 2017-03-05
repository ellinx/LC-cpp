#include "../Solutions.hpp"

using namespace std;

/***************** Construct The Tree From Inorder Traverse Of A Binary Search Tree *****************/
/*
Given the in-order traversal list of a binary search tree, generate the tree.
*/

TreeNode* help(vector<int>& inorder, int start, int end);

TreeNode* Solutions::ConstructFromInorder(vector<int>& inorder) {
    if (inorder.empty()) return NULL;
    int mid = inorder.size()/2;
    TreeNode* root = new TreeNode(inorder[mid]);
    if (inorder.size()==1) return root;
    
    root->left = help(inorder,0,mid-1);
    root->right = help(inorder,mid+1,inorder.size()-1);
    return root;
}

TreeNode* help(vector<int>& inorder, int start, int end) {
    if (start>end) return NULL;
    
    TreeNode* root = new TreeNode(inorder[start]);
    if (start==end) return root;
    
    int mid = start+(end-start)/2;
    root->left = help(inorder,0,mid-1);
    root->right = help(inorder,mid+1,inorder.size()-1);
    return root;
}
