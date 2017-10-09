
/***************** Largest Divisible Subset *****************/
/*
 Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
 
 If there are multiple solutions, return any subset is fine.
 
 Example 1:
 
 nums: [1,2,3]
 
 Result: [1,2] (of course, [1,3] will also be ok)
 Example 2:
 
 nums: [1,2,4,8]
 
 Result: [1,2,4,8]
 */

#include "../Solutions.hpp"
#include "../Tester.hpp"

vector<int> Solutions::largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    if (n==0) return res;
    vector<vector<int>> dp(n, vector<int>());
    
    sort(nums.begin(),nums.end());
    
    dp[0].push_back(nums[0]);
    res = dp[0];
    for (int i=1;i<n;i++) {
        dp[i] = vector<int>(1,nums[i]);
        for (int j=0;j<i;j++) {
            if (nums[i]%dp[j].front()==0 && nums[i]%dp[j].back()==0 && dp[i].size()-1<dp[j].size()) {
                dp[i] = dp[j];
                dp[i].push_back(nums[i]);
            }
        }
        if (dp[i].size()>res.size()) {
            res = dp[i];
        }
    }
    Tester::print(dp);
    return res;
}
