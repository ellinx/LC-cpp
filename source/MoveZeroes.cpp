#include "../Solutions.hpp"
using namespace std;

/*********** Move Zeroes ************/
/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

 For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
*/
void Solutions::moveZeroes(vector<int>& nums) {
    int index1=0;
    int index2=0;
    while (index2<nums.size()) {
        if (nums[index2]==0) index2++;
        else {
            nums[index1++] = nums[index2++];
        }
    }
    while (index1<nums.size()) {
        nums[index1++] = 0;
    }
}
