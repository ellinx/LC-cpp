#include "../Solutions.hpp"

using namespace std;

/***************** SubsetII *****************/

/*
 Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 
 Note: The solution set must not contain duplicate subsets.
 
 For example,
 If nums = [1,2,2], a solution is:
 
 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
*/

vector<vector<int>> Solutions::subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back(vector<int>());
    sort(nums.begin(),nums.end());
    
    for (int i=0;i<nums.size();i++) {
        int count = 1;
        while(i<nums.size()-1 && nums[i]==nums[i+1]) {
            count++;
            i++;
        }
        vector<vector<int>> tmp = res;
        for (int j=0;j<tmp.size();j++) {
            for (int k=0;k<count;k++) {
                tmp[j].push_back(nums[i]);
                res.push_back(tmp[j]);
            }
        }
    }
    return res;
}
