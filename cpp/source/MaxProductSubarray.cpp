#include "../Solutions.hpp"

using namespace std;

/***************** Maximum Product Subarray  *****************/
/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
*/

int Solutions::maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int maxHere = 0;
    int minHere = 0;
    int maxPre = 1;
    int minPre = 1;
    int res=INT_MIN;
    for (int i=0;i<nums.size();i++) {
        maxHere = max(max(maxPre*nums[i],minPre*nums[i]),nums[i]);
        minHere = min(min(maxPre*nums[i],minPre*nums[i]),nums[i]);
        res = max(res,maxHere);
        maxPre = maxHere;
        minPre = minHere;
    }
    return res;
}
