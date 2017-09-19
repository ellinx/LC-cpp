/***************** Rotate List *****************/
/*
 Given a list, rotate the list to the right by k places, where k is non-negative.
 
 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
 */

#include "../Solutions.hpp"
#include "../main.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solutions::rotateRight(ListNode* head, int k) {
    vector<int> nums;
    ListNode* cur = head;
    if (cur==NULL) return NULL;
    
    while (cur->next!=NULL) {
        nums.push_back(cur->val);
        cur = cur->next;
    }
    nums.push_back(cur->val);
    
    cur = head;
    printVector(nums);
    k %= nums.size();
    for (int i=nums.size()-k;i<nums.size();i++) {
        cur->val = nums[i];
        cur = cur->next;
    }
    
    for (int i=0;i<nums.size()-k;i++) {
        cur->val = nums[i];
        cur = cur->next;
    }
    
    return head;
}
