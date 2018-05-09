
#include "../Tester.hpp"

/***************** Serialize And Deserialize BST *****************/

/*
 Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 
 Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
 
 The encoded string should be as compact as possible.
 
 Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class SerializeAndDeserializeBST {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root==NULL) return "";
        
        string res = to_string(root->val);
        string left = serialize(root->left);
        string right = serialize(root->right);
        
        if (!left.empty())
            res += ","+left;
        if (!right.empty())
            res += ","+right;
        //cout<<res<<endl;
        return res;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        
        int start = 0;
        int end = 0;
        //find first number
        while (end<data.size() && data[end]!=',') {
            end++;
        }
        TreeNode* root = new TreeNode(stoi(data.substr(0,end)));
        
        int leftStart = -1;
        int rightStart = -1;
        if (data[end]==','){
            start = ++end;
        } else {
            //only one value
            return root;
        }
        
        while (end<data.size()) {
            while (end<data.size() && data[end]!=',') {
                end++;
            }
            int cur = stoi(data.substr(start,end-start));
            if (cur < root->val) {
                //still left child
                if (leftStart==-1)
                    leftStart = start;
                
                if (data[end]==','){
                    start = ++end;
                } else {
                    //no right child
                    break;
                }
            } else {
                rightStart = start;
                break;
            }
        }
        
        
        if (leftStart!=-1) {
            int leftEnd = (rightStart==-1)?data.size()-1:rightStart-2;
            string leftStr = data.substr(leftStart,leftEnd-leftStart+1);
            //cout<<"leftStr="<<leftStr<<endl;
            root->left = deserialize(leftStr);
            
        }
        if (rightStart!=-1) {
            string rightStr = data.substr(rightStart);
            root->right = deserialize(rightStr);
        }
        
        return root;
    }
};

// Your SerializeAndDeserializeBST object will be instantiated and called as such:
// SerializeAndDeserializeBST codec;
// codec.deserialize(codec.serialize(root));
