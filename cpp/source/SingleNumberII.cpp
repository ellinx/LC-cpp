#include "../Solutions.hpp"
using namespace std;

/*************** Single Number II **************/
/*
 Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
 
 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

int Solutions::singleNumberII(vector<int>& nums) {
    unordered_map<int,int> mp;
    for (int num : nums) {
        if (mp.find(num)==mp.end()) {
            mp[num] = 1;
        } else {
            mp[num]++;
        }
    }
    
    for (auto& kv : mp) {
        if (kv.second==1) {
            return kv.first;
        }
    }
    
    return 0;
}
