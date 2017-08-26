#include "../Solutions.hpp"
using namespace std;

/*************** Wiggle Sort II **************/
/*
 Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
 
 Example:
 (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
 (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
 
 Note:
 You may assume all input has valid answer.
 
 Follow Up:
 Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

void Solutions::wiggleSortII(vector<int>& nums) {
    int n = nums.size();
    vector<int> sortedNum(nums.begin(),nums.end());
    sort(sortedNum.begin(),sortedNum.end());
    
    for (int i=0;i<(n+1)/2;i++) {
        nums[2*i] = sortedNum[(n+1)/2-1-i];
    }
    for (int i=(n+1)/2;i<n;i++) {
        nums[2*(i-(n+1)/2)+1] = sortedNum[(3*n-1)/2-i];
    }
}
