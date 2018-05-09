
/***************** Find The Duplicate Number *****************/

/*
 Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 
 Note:
 1.You must not modify the array (assume the array is read only).
 2.You must use only constant, O(1) extra space.
 3.Your runtime complexity should be less than O(n^2).
 4.There is only one duplicate number in the array, but it could be repeated more than once.
 
 */

#include "../Solutions.hpp"

//O(nlg(n))
int Solutions::findDuplicate(vector<int>& nums) {
    int start = 1;
    int end = nums.size()-1;
    int count = 0;

    while (start < end) {
        //cout<<"start="<<start<<",end="<<end<<endl;
        int mid = (end-start)/2+start;
        count = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]>mid && nums[i]<=end) {
                count++;
            }
        }
        //cout<<"mid="<<mid<<",count="<<count<<endl;
        if (count>(end-start+1)/2) {
            start = mid+1;
        } else {
            end = mid;
        }
    }
    return start;
}
