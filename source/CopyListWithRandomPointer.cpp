
/***************** Copy List With Random Pointer *****************/
/*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 
 Return a deep copy of the list.
 */


#include "../Solutions.hpp"

RandomListNode *DFSHelpCopy(RandomListNode *head, unordered_map<int, RandomListNode*>& mp);
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

RandomListNode *copyRandomList(RandomListNode *head) {
    unordered_map<int, RandomListNode*> mp;
    if (head==NULL) return NULL;
    
    return DFSHelpCopy(head, mp);
}

//DFS
RandomListNode *DFSHelpCopy(RandomListNode *head, unordered_map<int, RandomListNode*>& mp) {
    if (mp.find(head->label)!=mp.end()) {
        return mp[head->label];
    }
    
    RandomListNode* newHead = new RandomListNode(head->label);
    mp[head->label] = newHead;
    
    if (head->next!=NULL) {
        newHead->next = DFSHelpCopy(head->next, mp);
    }
    if (head->random!=NULL) {
        newHead->random = DFSHelpCopy(head->random, mp);
    }
    return newHead;
}
