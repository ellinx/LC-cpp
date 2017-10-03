
/***************** Count Complete Tree Nodes *****************/
/*
 Given a string, calculate the number of substring which is palindrome.
 */

#include "../Solutions.hpp"
#include "../Tester.hpp"

int Solutions::countNodes(TreeNode* root) {
    if (root==NULL) return 0;
    
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    int lh = 1, rh =1;
    
    while (l!=NULL) {
        lh++;
        l = l->left;
    }
    while (r!=NULL) {
        rh++;
        r = r->right;
    }
    
    if (lh==rh) return (1<<lh)-1;
    
    return countNodes(root->left) + countNodes(root->right) +1;
}

//BFS
int countNodes(TreeNode* root) {
    if (root==NULL) return 0;
    
    int sum = 0;
    vector<TreeNode*> level(1,root);
    while (!level.empty()) {
        vector<TreeNode*> next;
        for (int i=0;i<level.size();i++) {
            if (level[i]->left!=NULL) {
                next.push_back(level[i]->left);
            }
            
            if (level[i]->right!=NULL) {
                next.push_back(level[i]->right);
            }
        }
        sum += level.size();
        level = next;
    }
    return sum;
}
