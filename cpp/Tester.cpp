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


//print functions
void Tester::print(int n){
    cout<<n<<endl;
}

void Tester::print(string s) {
    cout<<s<<endl;
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
