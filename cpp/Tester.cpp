//
//  Tester.cpp
//  AlgSolutions
//
//  Created by LXU on 9/19/17.
//  Copyright © 2017 LXU. All rights reserved.
//

#include "Tester.hpp"

ListNode* Tester::initListInt(vector<int> vec) {
    
    ListNode* head = new ListNode(vec[0]);
    ListNode* cur = head;
    
    for (int i=1;i<vec.size();i++) {
        cur->next = new ListNode(vec[i]);
        cur = cur->next;
    }
    
    return head;
}

vector<vector<char>> Tester::initMatrixChar(vector<string>& vec) {
    vector<vector<char>> res;
    for (int i=0;i<vec.size();i++) {
        vector<char> sub;
        for (char a : vec[i]) {
            sub.push_back(a);
        }
        res.push_back(sub);
    }
    return res;
}

TreeNode* initBSTIntHelper(vector<int>& vec, int start, int end) {
    TreeNode* root = new TreeNode(vec[start]);
    if (end==start) return root;
    int leftStart = -1;
    int leftEnd = -1;
    int rightStart = -1;
    int rightEnd = -1;
    
    if (vec[start+1]<vec[start]) {
        //left sub tree after root node
        leftStart = start+1;
        for (int i=start+2;i<=end;i++) {
            if (vec[i]>vec[start]) {
                leftEnd = i-1;
                rightStart = i;
                rightEnd = end;
                break;
            }
        }
        if (rightStart==-1) {
            leftEnd = end;
        }
    } else {
        //right sub tree after root node
        rightStart = start+1;
        for (int i=start+2;i<=end;i++) {
            if (vec[i]<vec[start]) {
                rightEnd = i-1;
                leftStart = i;
                leftEnd = end;
                break;
            }
        }
        if (leftStart == -1) {
            rightEnd = end;
        }
    }
    cout<<"leftStart="<<leftStart<<",leftEnd="<<leftEnd<<endl;
    cout<<"rightStart="<<rightStart<<",rightEnd="<<rightEnd<<endl;
    root->left = (leftStart==-1)?NULL:initBSTIntHelper(vec, leftStart, leftEnd);
    root->right = (rightStart==-1)?NULL:initBSTIntHelper(vec, rightStart, rightEnd);
    
    return root;
}
//input is like [root,leftNodes, rightNodes] or [root, rightNodes, leftNodes]
TreeNode* Tester::initBSTInt(vector<int> vec) {
    return initBSTIntHelper(vec, 0, vec.size()-1);
}


//print functions
void Tester::print(int n){
    cout<<n<<endl;
}

void Tester::print(long long n){
    cout<<n<<endl;
}

void Tester::print(string s) {
    cout<<s<<endl;
}

void Tester::print(Interval& interval) {
    cout<<"["<<interval.start<<","<<interval.end<<"]";
}

void Tester::print(vector<int>& vec){
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<vec[i];
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void Tester::print(vector<string>& vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<vec[i];
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void Tester::print(vector<bool>& vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<vec[i];
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void Tester::print(vector<char>& vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<vec[i];
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void Tester::print(vector<pair<int,int>>& vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<"["<<vec[i].first<<","<<vec[i].second<<"]";
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void Tester::print(vector<pair<string,int>>& vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<"["<<vec[i].first<<","<<vec[i].second<<"]";
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void Tester::print(vector<Interval>& vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<"["<<vec[i].start<<","<<vec[i].end<<"]";
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void Tester::print(vector<TreeNode*>& vec) {
    cout<<"[";
    for (int i=0;i<vec.size();i++) {
        cout<<vec[i]->val;
        if (i<vec.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void Tester::print(ListNode* head) {
    cout<<"[";
    while (head != NULL) {
        cout<<head->val;
        head = head->next;
        if (head != NULL) {
            cout<<"->";
        }
    }
    cout<<"]"<<endl;
}

void Tester::print(vector<vector<int>>& matrix) {
    for (int i=0;i<matrix.size();i++) {
        Tester::print(matrix[i]);
    }
}
void Tester::print(vector<vector<char>>& matrix) {
    for (int i=0;i<matrix.size();i++) {
        Tester::print(matrix[i]);
    }
}
void Tester::print(vector<vector<string>>& matrix) {
    for (int i=0;i<matrix.size();i++) {
        Tester::print(matrix[i]);
    }
}

void Tester::print(stack<int> stk) {
    cout<<"[";
    while (!stk.empty()) {
        cout<<stk.top();
        stk.pop();
        if (!stk.empty()) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

void Tester::print(TreeNode* root) {
    vector<vector<string>> levelOrder;
    vector<TreeNode*> levelTN;
    
    cout<<"["<<endl;
    if (root==NULL) {
        cout<<"#"<<endl;
        cout<<"]"<<endl;
        return;
    }
    
    levelTN.push_back(root);
    while (!levelTN.empty()) {
        vector<string> levelStr;
        vector<TreeNode*> nextLevel;
        for (int i=0;i<levelTN.size();i++) {
            if (levelTN[i]==NULL) {
                levelStr.push_back("#");
                continue;
            }
            levelStr.push_back(to_string(levelTN[i]->val));
            nextLevel.push_back(levelTN[i]->left);
            nextLevel.push_back(levelTN[i]->right);
        }
        levelOrder.push_back(levelStr);
        levelTN = nextLevel;
    }
    
    for (auto each : levelOrder)
        Tester::print(each);
    
    cout<<"]"<<endl;
}
