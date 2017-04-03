#include "../Solutions.hpp"

using namespace std;

/***************** Add Two Numbers *****************/
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solutions::addTwoNumbers(ListNode* l1, ListNode* l2) {

	int sum = l1->val + l2->val;
	int carry = sum/10;
	sum %= 10;
	ListNode* head = new ListNode(sum);
	ListNode* cur = head;
	l1 = l1->next;
	l2 = l2->next;

	// l1 and l2 are not empty
	while (l1 != NULL & l2 != NULL) {
		sum = l1->val + l2->val + carry;
		carry = sum/10;
		sum %= 10;
		cur->next = new ListNode(sum);
		cur = cur->next;
		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1 != NULL) {
		sum = l1->val + carry;
		carry = sum/10;
		sum %= 10;
		cur->next = new ListNode(sum);
		cur = cur->next;
		l1 = l1->next;
	}

	while (l2 != NULL) {
		sum = l2->val + carry;
		carry = sum/10;
		sum %= 10;
		cur->next = new ListNode(sum);
		cur = cur->next;
		l2 = l2->next;
	}

	if (carry != 0) {
		cur->next = new ListNode(carry);
	}

	return head;
}