#include "../Solutions.hpp"
#include "../Tester.hpp"

/***************** Find All Duplicates In an Array *****************/
/*
 Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
 Find all the elements that appear twice in this array.
 
 Could you do it without extra space and in O(n) runtime?
 
 Example:
 Input:
 [4,3,2,7,8,2,3,1]
 
 Output:
 [2,3]
 */


vector<int> Solutions::findDuplicates(vector<int>& nums) {
    vector<int> res;
    
    //put num in index num-1
    int i=0;
    while (i<nums.size()) {
        if (nums[nums[i]-1] != nums[i])
            swap(nums[nums[i]-1], nums[i]);
        else
            i++;
    }
    
    for (i=0;i<nums.size();i++) {
        if (nums[i]!=i+1) {
            res.push_back(nums[i]);
        }
    }
    return res;
}
