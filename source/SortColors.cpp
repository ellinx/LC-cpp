#include "../Solutions.hpp"

using namespace std;

/***************** Sort Colors *****************/

/*
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 
 Note:
 You are not suppose to use the library's sort function for this problem.
 
 click to show follow up.
 
 Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 
 Could you come up with an one-pass algorithm using only constant space?
*/

void Solutions::sortColors(vector<int>& nums) {
    if (nums.empty()) return;
    
    int index0 = 0;
    int index1 = 0;
    int index2 = nums.size()-1;
    while (index1 < index2) {
        while (nums[index1]==2 && index1<index2) {
            swap(nums[index1],nums[index2]);
            index2--;
        }
        while (nums[index1]==0 && index1>index0) {
            swap(nums[index1],nums[index0]);
            index0++;
        }
        index1++;
    }
}
