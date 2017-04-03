#include "../Solutions.hpp"

using namespace std;

/***************** Two Sum *****************/
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

vector<int> Solutions::twoSum(vector<int>& nums, int target) {
	unordered_map<int,int> mp;
	vector<int> res(2,0);

	for (int i=0;i<nums.size();i++) {
		auto iter = mp.find(target - nums[i]);
		if (iter != mp.end()) {
			res[0] = iter->second;
			res[1] = i;
			return res;
		} else {
			mp[nums[i]] = i;
		}
	}
	return res;
}