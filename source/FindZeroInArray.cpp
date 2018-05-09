#include "../Solutions.hpp"

using namespace std;

/***************** Find Zero in Array *****************/

/*
 Given an array and an index, determine whether we can get zero value based on the calculated next index. If we can find zero in the array, return true; if we can't or index out of boundary, return false.
 Here is how to calculate next index:
 nextIndex = index - Array[index] or index + Array[index]
 
 */

bool Solutions::canFindZero(vector<int>& nums, int index) {
    if (index<0 || index>=nums.size()) {
        return false;
    }
    if (nums[index]==0) return true;
    
    int nextIndex1 = index - nums[index];
    int nextIndex2 = index + nums[index];
    
    return (canFindZero(nums, nextIndex1) || canFindZero(nums, nextIndex2) );
}
