
/***************** Contains Duplicate *****************/
/*
 Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

#include "../Solutions.hpp"
#include "../Tester.hpp"

bool Solutions::containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for (int i=1;i<nums.size();i++) {
        if (nums[i]==nums[i-1]) return true;
    }
    return false;
}

/***************** Contains Duplicate II *****************/
/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

bool Solutions::containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> numSet;
    for (int i=0;i<nums.size();i++) {
        if (i>k) {
            numSet.erase(nums[i-k-1]);
        }
        if (numSet.find(nums[i])!=numSet.end()) return true;
        numSet.insert(nums[i]);
    }
    return false;
}

/***************** Contains Duplicate III *****************/
/*
 Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
 */

bool Solutions::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.size()<2) return false;
    
    set<long long> vals;
    for (int i=0;i<nums.size();i++) {
        if (i>k) {
            vals.erase((long long)nums[i-k-1]);
        }
        

        auto iter = vals.lower_bound((long long)nums[i]-(long long)t);//x-nums[i]>=-t => x>=nums[i]-t
        if (iter!=vals.end() && (long long)*iter-(long long)nums[i] <= t) return true;
        
        vals.insert((long long)nums[i]);
    }
    return false;
}
