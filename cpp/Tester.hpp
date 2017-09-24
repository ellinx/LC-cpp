//
//  Tester.hpp
//  AlgSolutions
//
//  Created by LXU on 9/19/17.
//  Copyright © 2017 LXU. All rights reserved.
//

#ifndef Tester_hpp
#define Tester_hpp

#include "Solutions.hpp"

#endif /* Tester_hpp */

class Tester {
    
public:
    static ListNode* initListInt(vector<int> vec);
    static vector<vector<char>> initMatrixChar(vector<string>& vec);
    
    static void print(int n);
    static void print(string s);
    static void print(ListNode* head);
    
    static void print(vector<int>& vec);
    static void print(vector<string>& vec);
    static void print(vector<bool>& vec);
    static void print(vector<char>& vec);
    static void print(vector<pair<int,int>>& vec);
    static void print(vector<Interval> & vec);
    
    static void print(vector<vector<int>>& matrix);
    static void print(vector<vector<char>>& matrix);
    
    static void print(stack<int> stk);
};
