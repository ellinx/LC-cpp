#include "../Solutions.hpp"

using namespace std;

/***************** Merge k Sorted Lists *****************/
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

static bool compList(ListNode* a, ListNode* b);

ListNode* Solutions::mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,function<bool(ListNode*,ListNode*)>> pq(compList);
    ListNode* head = NULL;
    ListNode* cur = NULL;
    if (lists.empty()) return head;
    
    for (int i=0;i<lists.size();i++) {
        if (lists[i]!=NULL) pq.push(lists[i]);
    }
    
    while(!pq.empty()) {
        ListNode* tmp = pq.top();
        pq.pop();
        if (cur==NULL) {
            head = tmp;
            cur = tmp;
        }
        else {
            cur->next = tmp;
            cur = cur->next;
        }
        if (tmp->next!=NULL) {
            tmp = tmp->next;
            pq.push(tmp);
        }
    }
    return head;
}

static bool compList(ListNode* a, ListNode* b) {
    return (a->val>=b->val);
}
