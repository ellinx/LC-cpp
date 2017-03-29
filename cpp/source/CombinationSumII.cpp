#include "../Solutions.hpp"

using namespace std;

/***************** Combination Sum II *****************/
/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 Each number in C may only be used once in the combination.
 
 Note:
 All numbers (including target) will be positive integers.
 The solution set must not contain duplicate combinations.
 For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 A solution set is:
 [
 [1, 7],
 [1, 2, 5],
 [2, 6],
 [1, 1, 6]
 ]
*/

void help(int target, vector<int>& candidates, vector<int>& cand, vector<vector<int>>& res, int start);

vector<vector<int>> Solutions::combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cand;
    if (candidates.empty()) return res;
    
    sort(candidates.begin(),candidates.end());
    help(target,candidates,cand,res,0);
    return res;
}

void help(int target, vector<int>& candidates, vector<int>& cand, vector<vector<int>>& res, int start) {
    if (target==0) {
        res.push_back(cand);
        return;
    }
    
    for (int i=start;i<candidates.size();i++) {
        if (candidates[i]>target) break;
        if (i==start || candidates[i-1]!=candidates[i]) {
            cand.push_back(candidates[i]);
            help(target-candidates[i],candidates,cand,res,i+1);
            cand.pop_back();
        }
    }
}
