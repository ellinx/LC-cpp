#include "../Solutions.hpp"

using namespace std;

/***************** Reverse Linked List *****************/
/*
Reverse a singly linked list.
*/

ListNode* Solutions::reverseList(ListNode* head) {
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
