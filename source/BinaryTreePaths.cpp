#include "../Solutions.hpp"

using namespace std;

/***************** Binary Tree Paths *****************/
/*
 Given a binary tree, return all root-to-leaf paths.
 
 For example, given the following binary tree:
 
    1
  /   \
 2     3
  \
   5
 All root-to-leaf paths are:
 
 ["1->2->5", "1->3"]
*/
void DFS(TreeNode* root,string& buildBlk, vector<string>& res);

vector<string> Solutions::binaryTreePaths(TreeNode* root) {
    vector<string> res;
    string buildBlk;
    
    if (root==NULL) return res;
    DFS(root,buildBlk,res);
    return res;
}

void DFS(TreeNode* root,string& buildBlk, vector<string>& res) {
    string tmp = buildBlk;
    buildBlk += to_string(root->val) + "->";
    if (root->left==NULL && root->right==NULL) {
        buildBlk = buildBlk.substr(0,buildBlk.size()-2);
        res.push_back(buildBlk);
        buildBlk = tmp;
        return;
    }
    if (root->left!=NULL) DFS(root->left,buildBlk,res);
    if (root->right!=NULL) DFS(root->right,buildBlk,res);
    buildBlk = tmp;
}
