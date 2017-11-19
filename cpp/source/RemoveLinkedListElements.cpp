
#include "../Solutions.hpp"

/*********** Remove Linked List Elements **************/
/*
 Remove all elements from a linked list of integers that have value val.
 
 Example
 Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 Return: 1 --> 2 --> 3 --> 4 --> 5
 */

ListNode* Solutions::removeElements(ListNode* head, int val) {
    ListNode* newHead = NULL;
    if (head==NULL) return newHead;
    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur!=NULL) {
        if (newHead==NULL) {
            if (cur->val==val) {
                pre = cur;
                cur = cur->next;
            } else {
                newHead = cur;
                pre = cur;
                cur = cur->next;
            }
        } else {
            if (cur->val==val) {
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
    }
    return newHead;
}
