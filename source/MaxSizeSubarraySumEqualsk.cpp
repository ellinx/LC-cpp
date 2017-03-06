#include "../Solutions.hpp"

using namespace std;

/***************** Maximum Size Subarray Sum Equals k *****************/
/*
 Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
 
 Note:
 The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
 
 Example 1:
 Given nums = [1, -1, 5, -2, 3], k = 3,
 return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
*/

 
int Solutions::maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int res=0;
    int sum = 0;
    
    for (int i=0;i<nums.size();i++) {
        sum += nums[i];
        
        if (sum==k) {
            if (res==0 || res<i+1) {
                res = i;
            }
        }
        
        auto iter = mp.find(k-sum);
        if (iter!=mp.end()) {
            if (res==0 || res<i+1-iter->second) {
                res = i+1-iter->second;
            }
        }
        
        
        iter = mp.find(sum);
        if (iter==mp.end()) {
            mp[sum] = i;
        }
    }
    return res;
}
