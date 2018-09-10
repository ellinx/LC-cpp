#include "../Solutions.hpp"

/*********** Reverse Linked List II *************/
/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,

 return 1->4->3->2->5->NULL.

 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
 */

ListNode* Solutions::reverseBetween(ListNode* head, int m, int n) {
    if (head==NULL || head->next==NULL) return head;

    ListNode* left = NULL;
    ListNode* pre = head;
    ListNode* cur = head;
    ListNode* right = NULL;

    for (int i=1;i<=n;i++) {
        if (i==m-1) {
            left = cur;
            pre = cur->next;
        }
        if (i==n) {
            right = cur->next;
        }
        cur = cur->next;
    }
    cur = pre->next;

    //reverse
    while (cur!=right) {
        ListNode* nextCur = cur->next;
        if ((left==NULL && pre==head) || ( left!=NULL && left->next==pre)) {
            pre->next = right;
        }
        cur->next = pre;
        pre = cur;
        cur = nextCur;
    }
    if (left!=NULL) {
        left->next = pre;
        return head;
    }
    return pre;
}
