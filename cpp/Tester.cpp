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
