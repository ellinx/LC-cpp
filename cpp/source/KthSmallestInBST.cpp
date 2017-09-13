
/***************** Kth Largest In Array *****************/

/*
 Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 
 For example,
 Given [3,2,1,5,6,4] and k = 2, return 5.
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include "../Solutions.hpp"

void inOrder(TreeNode* root, vector<int>& res, int k);

int Solutions::kthSmallest(TreeNode* root, int k) {
    vector<int> res;
    inOrder(root, res, k);
    return res.back();
}

void inOrder(TreeNode* root, vector<int>& res, int k) {
    if (res.size()==k) return;
    
    if (root->left!=NULL) {
        inOrder(root->left, res, k);
    }
    
    if (res.size()==k) return;
    
    res.push_back(root->val);
    
    if (res.size()==k) return;
    if (root->right!=NULL) {
        inOrder(root->right, res, k);
    }
}
