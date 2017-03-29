#include "../Solutions.hpp"
using namespace std;
/************ Permutations ****************/
/*
 Given a collection of distinct numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
vector<vector<int>> Solutions::permute(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() == 1) {
        res.push_back(nums);
        return res;
    }

    for (int i=0;i<nums.size();i++) {
        vector<int> dummy(nums);
        dummy[i] = dummy[dummy.size()-1];
        dummy.pop_back();

        vector<vector<int>> pre_result = permute(dummy);
        for (vector<vector<int>>::iterator it=pre_result.begin();it!=pre_result.end();it++) {
            it->push_back(nums[i]);
            res.push_back(*it);
        }
    }
    return res;
}
