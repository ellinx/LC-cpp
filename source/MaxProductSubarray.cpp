#include "../Solutions.hpp"

using namespace std;

/***************** Maximum Product Subarray  *****************/
/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
*/

int Solutions::maxProduct(vector<int>& nums) {
    int res=INT_MIN;
    for (int start=0;start<nums.size();start++) {
        int product = 1;
        for (int i=start;i<nums.size();i++) {
            product *= nums[i];
            if (product>res) res = product;
        }
    }
    return res;
}
