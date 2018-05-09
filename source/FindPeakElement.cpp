
/***************** Find Peak Element *****************/
/*
 A peak element is an element that is greater than its neighbors.
 
 Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 
 The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 
 You may imagine that num[-1] = num[n] = -∞.
 
 For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 
 Note:
 Your solution should be in logarithmic complexity.
 */

#include "../Solutions.hpp"

int helpFind(vector<int>& nums, int left, int right);

int Solutions::findPeakElement(vector<int>& nums) {
    return helpFind(nums, 0, nums.size()-1);
}

int helpFind(vector<int>& nums, int left, int right) {
    if (left==right) return left;
    
    int mid = left+(right-left)/2;
    if (nums[mid]>nums[mid+1]) {
        return helpFind(nums, left, mid);
    } else {
        return helpFind(nums, mid+1, right);
    }
}
