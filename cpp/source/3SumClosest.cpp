
/***************** 3Sum Closest *****************/
/*
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 
 For example, given array S = {-1 2 1 -4}, and target = 1.
 
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "../Solutions.hpp"

int Solutions::threeSumClosest(vector<int>& nums, int target) {
    int res=nums[0]+nums[1]+nums[2];
    int first = 0;
    int second = 0;
    int third = 0;
    sort(nums.begin(),nums.end());
    for (first=0;first<nums.size()-2;first++) {
        second = first+1;
        third = nums.size()-1;
        while (second<third) {
            int sum = nums[first]+nums[second]+nums[third];
            if (sum==target) return sum;
            if (abs(sum-target)<abs(res-target)) {
                res = sum;
            }
            if (sum>target) third--;
            else second++;
        }
    }
    return res;
}
