#include "../Solutions.hpp"

using namespace std;

/***************** Verify Preorder Serialization of a Binary Tree *****************/
/*
 One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
 
      _9_
     /   \
    3     2
   / \   / \
  4   1  #  6
 / \ / \   / \
 # # # #   # #
 For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 
 Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
 
 Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
 
 You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
 
 Example 1:
 "9,3,4,#,#,1,#,#,2,#,6,#,#"
 Return true
 
 Example 2:
 "1,#"
 Return false
 
 Example 3:
 "9,#,#,1"
 Return false
 */

void printstk(stack<string> stk) {
    vector<string> vec;
    while (!stk.empty()) {
        vec.push_back(stk.top());
        stk.pop();
    }
    reverse(vec.begin(), vec.end());
    for (string a : vec) {
        cout<<a<<",";
    }
    cout<<endl;
}

bool Solutions::isValidSerialization(string preorder) {
    stack<string> stk;
    vector<string> preorderV;
    int left = 0;
    int right = 0;
    
    while (right<preorder.size()) {
        if (preorder[right]==',') {
            preorderV.push_back(preorder.substr(left,right-left));
            left = ++right;
        } else {
            ++right;
        }
        
        //cout<<"right="<<right<<endl;
    }
    if (left<preorder.size()) {
        preorderV.push_back(preorder.substr(left,right-left));
    }
    
    
    for (string str : preorderV) {
        stk.push(str);
        //printstk(stk);
        if (str=="#") {
            while (!stk.empty()) {
                if (stk.size()>=3) {
                    string third = stk.top();
                    stk.pop();
                    string second = stk.top();
                    stk.pop();
                    string first = stk.top();
                    stk.pop();
                    if (third=="#" && second=="#" && first!="#") {
                        stk.push("#");
                    } else {
                        stk.push(first);
                        stk.push(second);
                        stk.push(third);
                        break;
                    }
                } else {
                    break;
                }
            }
        }
    }

    //cout<<"last::";
    //printstk(stk);
    if (stk.size()==1 && stk.top()=="#") {
        return true;
    } else {
        return false;
    }
}
