#include "../Solutions.hpp"

/***************** Subset *****************/
/*
 Given a set of distinct integers, nums, return all possible subsets.
 
 Note: The solution set must not contain duplicate subsets.
 
 For example,
 If nums = [1,2,3], a solution is:
 
 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]
*/

//iterative
vector<vector<int>> Solutions::subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back(vector<int>());
    for (int i=0;i<nums.size();i++) {
        vector<vector<int>> tmp = res;
        for (int j=0;j<tmp.size();j++) {
            tmp[j].push_back(nums[i]);
            res.push_back(tmp[j]);
        }
    }
    return res;
}

//recursive

void helper(int start, int left, vector<int>& blk, vector<int>& nums, vector<vector<int>>& res);

vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) return vector<vector<int>>();
    
    vector<vector<int>> res;
    vector<int> blk;
    for (int i=0;i<=nums.size();i++) {
        helper(0,i,blk,nums,res);
    }
    return res;
}

void helper(int start, int left, vector<int>& blk, vector<int>& nums, vector<vector<int>>& res) {
    if (left==0) {
        res.push_back(blk);
        return;
    }
    
    for (int i=start;i<=nums.size()-left;i++) {
        blk.push_back(nums[i]);
        helper(i+1,left-1,blk,nums,res);
        blk.pop_back();
    }
}

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
