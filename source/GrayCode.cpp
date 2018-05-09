#include "../Solutions.hpp"

using namespace std;

/***************** Gray Code *****************/
/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

*/

vector<int> Solutions::grayCode(int n) {
    if (n==0) return {0};
	vector<int> pre;
	vector<int> cur(2,0);
	cur[1] = 1;
	if (n == 1) return cur;

	pre = cur;
	int bits = 1;
	while (bits < n) {
		int offset = 1<<bits;
		for (int i=pre.size()-1;i>=0;i--) {
			cur.push_back(pre[i]+offset);
		}
		bits++;
		pre = cur;
	}
	return cur;
}
