#include "../Solutions.hpp"

using namespace std;

/***************** Next Permutation *****************/
/*
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 
 If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 
 The replacement must be in-place, do not allocate extra memory.
 
 Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
*/

void Solutions::nextPermutation(vector<int>& nums) {
	int k=-1;
    for (int i=nums.size()-1;i>0;i--) {
		if (nums[i-1]<nums[i]) {
			k = i-1;
			break;
		}
	}

	int first = 0;
	int second = nums.size()-1;
	if (k==-1) {
		while(first<second) {
			int tmp = nums[second];
			nums[second] = nums[first];
			nums[first] = tmp;
			first++;
			second--;
		}
		return;
	}

	for (int i=nums.size()-1;i>k;i--) {
		if (nums[i]>nums[k]) {
			int tmp = nums[k];
			nums[k] = nums[i];
			nums[i] = tmp;
			break;
		}
	}

	first = k+1;
	second = nums.size()-1;
	while(first<second) {
		int tmp = nums[second];
		nums[second] = nums[first];
		nums[first] = tmp;
		first++;
		second--;
	}
}
