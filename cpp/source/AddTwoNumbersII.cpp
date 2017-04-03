#include "../Solutions.hpp"

using namespace std;

/***************** Add Two Numbers II *****************/
/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solutions::addTwoNumbersII(ListNode* l1, ListNode* l2) {
	stack<int> sk1;
	stack<int> sk2;
	stack<int> skSum;
	int carry = 0;

	while (l1 != NULL) {
		sk1.push(l1->val);
		l1 = l1->next;
	}
	while (l2 != NULL) {
		sk2.push(l2->val);
		l2 = l2->next;
	}

	while (!sk1.empty() && !sk2.empty()) {
		int sum = sk1.top() + sk2.top() + carry;
		carry = sum/10;
		sum %= 10;
		skSum.push(sum);
		sk1.pop();
		sk2.pop();
	}
	while (!sk1.empty()) {
		int sum = sk1.top() + carry;
		carry = sum/10;
		sum %= 10;
		skSum.push(sum);
		sk1.pop();
	}
	while (!sk2.empty()) {
		int sum = sk2.top() + carry;
		carry = sum/10;
		sum %= 10;
		skSum.push(sum);
		sk2.pop();
	}
	if (carry != 0) {
		skSum.push(carry);
	}

	ListNode* head = new ListNode(skSum.top());
	skSum.pop();
	ListNode* cur = head;
	while (!skSum.empty()) {
		cur->next = new ListNode(skSum.top());
		skSum.pop();
		cur = cur->next;
	}
	return head;
}