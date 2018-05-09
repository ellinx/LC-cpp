
/***************** Majority Element *****************/
/*
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 
 You may assume that the array is non-empty and the majority element always exist in the array.
 */

#include "../Solutions.hpp"

int Solutions::majorityElementI(vector<int>& nums) {
    int n = nums.size();
    int can = 0, count = 0;
    for (int i=0;i<n;i++) {
        if (can==nums[i]) {
            count++;
        } else if (count==0) {
            can = nums[i];
            count = 1;
        } else {
            count--;
        }
    }
    
    //no need to verify. Assumption is it exists.
    return can;
}

int majorityElementI(vector<int>& nums) {
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


//https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
//Boyer-Moore Majority Vote algorithm
vector<int> Solutions::majorityElementII(vector<int>& nums) {
    vector<int> res;
    int n = nums.size();
    int can1 = 0, count1 = 0;
    int can2 = 1, count2 = 0;
    for (int i=0;i<n;i++) {
        if (nums[i]==can1) {
            count1++;
        } else if (nums[i]==can2) {
            count2++;
        } else if (count1==0) {
            can1 = nums[i];
            count1 = 1;
        } else if (count2==0) {
            can2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    
    count1=0,count2=0;
    for (int i=0;i<n;i++) {
        if (can1==nums[i]) {
            count1++;
        }
        if (can2==nums[i]) {
            count2++;
        }
    }
    if (count1>n/3) res.push_back(can1);
    if (count2>n/3) res.push_back(can2);
    return res;
}
