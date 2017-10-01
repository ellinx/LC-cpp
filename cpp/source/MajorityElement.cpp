
/***************** Majority Element *****************/
/*
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 
 You may assume that the array is non-empty and the majority element always exist in the array.
 */

#include "../Solutions.hpp"

int Solutions::majorityElementI(vector<int>& nums) {
    unordered_map<int,int> mp;
    int n = nums.size();
    for (int i=0;i<n;i++) {
        if (mp.find(nums[i])!=mp.end()) {
            mp[nums[i]]++;
        } else {
            mp[nums[i]] = 1;
        }
        if (mp[nums[i]]>n/2) return nums[i];
    }
    return 0;
}

/***************** Majority Element II *****************/
/*
 Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 */

vector<int> Solutions::majorityElementII(vector<int>& nums) {
    
}
