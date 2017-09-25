
/***************** Reverse Linked List *****************/
/*
Reverse a singly linked list.
*/

#include "../Solutions.hpp"

ListNode* Solutions::reverseList(ListNode* head) {
    if (head==NULL || head->next==NULL) return head;
    
    ListNode* pre = head;
    ListNode* cur = head->next;
    while (cur!=NULL) {
        ListNode* nextCur = cur->next;
        if (pre == head) {
            pre->next = NULL;
        }
        cur->next = pre;
        pre = cur;
        cur = nextCur;
    }
    return pre;
}


//use O(n) space
ListNode* reverseList(ListNode* head) {
    if (head==NULL) return head;
    ListNode* cur = head;
    stack<int> sk;
    while (cur!=NULL) {
        sk.push(cur->val);
        cur = cur->next;
    }
    cur = head;
    while (!sk.empty()) {
        cur->val = sk.top();
        cur = cur->next;
        sk.pop();
    }
    return head;
}
