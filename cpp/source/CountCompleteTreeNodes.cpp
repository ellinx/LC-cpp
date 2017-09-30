
/***************** Count Complete Tree Nodes *****************/
/*
 Given a string, calculate the number of substring which is palindrome.
 */

#include "../Solutions.hpp"
#include "../Tester.hpp"

int Solutions::countNodes(TreeNode* root) {
    if (root==NULL) return 0;
    
    int sum = 0;
    int depth
    vector<TreeNode*> level(1,root);
    
}


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
