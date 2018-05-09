#include "../Solutions.hpp"

using namespace std;

/***************** Longest Consecutive Sequence  *****************/
/*
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 
*/

int Solutions::longestConsecutive(vector<int>& nums) {
	if (nums.empty()) return 0;
	unordered_set<int> numSet(nums.begin(),nums.end());
	int res=0;
	while (!numSet.empty()) {
		auto iter = numSet.begin();
		int cur = *iter;
		int left=0;
		int right=0;
		while(numSet.find(cur-1)!=numSet.end()) {
			numSet.erase(cur-1);
			cur--;
			left++;
		}
		cur = *iter;
		while(numSet.find(cur+1)!=numSet.end()) {
			numSet.erase(cur+1);
			cur++;
			right++;
		}
		numSet.erase(iter);
		res = max(res,left+1+right);
	}
	return res;
}