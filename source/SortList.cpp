
/***************** Sort List *****************/
/*
 Sort a linked list in O(n log n) time using constant space complexity.
 */

#include "../Solutions.hpp"

ListNode* mergeSort(ListNode* head);

ListNode* Solutions::sortList(ListNode* head) {
    if (head==NULL || head->next==NULL) return head;
    
    return mergeSort(head);
}

ListNode* mergeSort(ListNode* head) {
    int n=0;
    ListNode* cur = head;
    
    //calculate list length
    while (cur!=NULL) {
        n++;
        cur = cur->next;
    }
    if (n==1) return head;
    
    //separate list into two and sort them
    int mid = (n-1)/2;
    cur = head;
    for (int i=0;i<mid;i++) {
        cur = cur->next;
    }
    ListNode* midHead = cur->next;
    cur->next = NULL;
    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(midHead);
    
    //merge the two list
    if (left->val < right->val) {
        head = left;
        left = left->next;
    } else {
        head = right;
        right = right->next;
    }
    cur = head;
    while (left!=NULL && right!=NULL) {
        if (left->val < right->val) {
            cur->next = left;
            left = left->next;
        } else {
            cur->next = right;
            right = right->next;
        }
        cur = cur->next;
    }
    
    while (left!=NULL) {
        cur->next = left;
        left = left->next;
        cur = cur->next;
    }
    while (right!=NULL) {
        cur->next = right;
        right = right->next;
        cur = cur->next;
    }
    cur->next = NULL;
    return head;
}
