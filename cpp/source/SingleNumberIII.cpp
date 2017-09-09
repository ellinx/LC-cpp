#include "../Solutions.hpp"
using namespace std;

/*************** Single Number III **************/
/*
 Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

 For example:

 Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
*/

vector<int> Solutions::singleNumberIII(vector<int>& nums) {
    unordered_map<int, int> mp;
    vector<int> res;
    
    for (int num : nums) {
        if (mp.find(num)==mp.end()) {
            mp[num] = 1;
        } else {
            mp[num]++;
        }
    }
    
    for (auto& kv : mp) {
        if (kv.second==1) {
            res.push_back(kv.first);
        }
    }
    
    return res;
}
