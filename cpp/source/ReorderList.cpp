
/***************** Reorder List *****************/
/*
 Given a singly linked list L: L0->L1->…->Ln-1->Ln,
 reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->…
 
 You must do this in-place without altering the nodes' values.
 
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

#include "../Solutions.hpp"
#include "../Tester.hpp"

void Solutions::reorderList(ListNode* head) {
    ListNode* cur = head;
    
    if (head==NULL || head->next==NULL) return;
    
    int n = -1;
    int mid = 0;
    while(cur!=NULL) {
        n++;
        cur = cur->next;
    }
    
    mid = n/2+1;
    ListNode* midHead = head;
    for (int i=1;i<=mid;i++) {
        if (i==mid) {
            ListNode* cur = midHead;
            midHead = midHead->next;
            cur->next = NULL;
            break;
        }
        midHead = midHead->next;
    }
    Tester::print(head);
    Tester::print(midHead);
    
    //reverse second half
    ListNode* pre = midHead;
    cur = pre->next;
    while (cur!=NULL) {
        ListNode* nextCur = cur->next;
        if (pre==midHead) {
            pre->next = NULL;
        }
        cur->next = pre;
        pre = cur;
        cur = nextCur;
    }
    midHead = pre;
    
    
    
    cur = head;
    ListNode* midCur = midHead;
    //merge first half with reversed second half
    for (int i=0;i<mid;i++) {
        if (cur==NULL || midCur==NULL) break;
        
        ListNode* nextCur = cur->next;
        ListNode* nextMidCur = midCur->next;
        
        cur->next = midCur;
        midCur->next = nextCur;
        
        cur = nextCur;
        midCur = nextMidCur;
    }
}
