#include "../Solutions.hpp"

using namespace std;

/***************** 3 Sum *****************/
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

vector<vector<int>> Solutions::threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size()<3) return res;
	int first = 0;
	int second = 0;
	int third = 0;
	sort(nums.begin(),nums.end());
	while (first<nums.size()-2) {
		second = first+1;
		third = nums.size()-1;
		while(second<third) {
			int sum = nums[first]+nums[second]+nums[third];
			if (sum==0) {
				vector<int> tmp;
				tmp.push_back(nums[first]);
				tmp.push_back(nums[second]);
				tmp.push_back(nums[third]);
				res.push_back(tmp);
				second++;
				third--;
				while(nums[second]==nums[second-1]) second++;
				while(nums[third]==nums[third+1]) third--;
			} else if (sum>0) {
				third--;
				while(nums[third]==nums[third+1]) third--;
			} else {
				second++;
				while(nums[second]==nums[second-1]) second++;
			}
		}
		first++;
		while(nums[first]==nums[first-1]) first++;
	}
	return res;
}