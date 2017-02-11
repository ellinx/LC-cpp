#include "../Solutions.hpp"

using namespace std;

/***************** Minimum Size Subarray Sum  *****************/
/*
 Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

int Solutions::minSubArrayLen(int s, vector<int>& nums) {
	int res=INT_MAX;
	int start=0;
	int end=0;
	int sum=0;
	while (start<nums.size() && end<nums.size()) {
		if (sum>=s) {
			if (end-start+1<res) {
				res = end-start+1;
			}
			sum -= nums[start];
			start++;
		} else {
			end++;
			if (end<nums.size()) {
				sum += nums[end];
			}
		}
		cout<<"start="<<start<<", end="<<end<<endl;
	}
	if (res==INT_MAX) return 0;
	return res;
}
