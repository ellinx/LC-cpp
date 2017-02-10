#include "Solution.hpp"
using namespace std;

/*********** Move Zeroes ************/
/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

 For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
*/
void Solution::moveZeroes(vector<int>& nums) {
    int zero = 0;
    int noneZero = 0;
    while (noneZero < nums.size()) {
        if (nums[zero] != 0) {
            zero++;
        } else {
            if (noneZero == 0) {
                noneZero = zero + 1;
            } else {
                while (noneZero < nums.size()) {
                    if (nums[noneZero] == 0) {
                        noneZero++;
                    } else {
                        break;
                    }
                }
                if (noneZero < nums.size()) {
                    nums[zero] = nums[noneZero];
                    nums[noneZero] = 0;
                    zero++;
                    noneZero++;
                }
            }
        }
        //cout<< "Z=" << zero <<"; NZ=" << noneZero <<endl;
    }
}
