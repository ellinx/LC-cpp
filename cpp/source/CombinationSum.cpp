#include "../Solutions.hpp"

using namespace std;

/***************** Combination Sum *****************/
/*
 Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 The same repeated number may be chosen from C unlimited number of times.
 
 Note:
 All numbers (including target) will be positive integers.
 The solution set must not contain duplicate combinations.
 For example, given candidate set [2, 3, 6, 7] and target 7,
 A solution set is:
 [
 [7],
 [2, 2, 3]
 ]
 */
void help(int target, vector<int>& cand, vector<vector<int>>& res, vector<int>& candidates, int start);

vector<vector<int>> Solutions::combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cand;
    if (candidates.empty()) return res;
    sort(candidates.begin(),candidates.end());
    help(target,cand,res,candidates,0);
    return res;
}

void help(int target, vector<int>& cand, vector<vector<int>>& res, vector<int>& candidates, int start) {
    if (target==0) {
        res.push_back(cand);
        return;
    }
    
    for (int i=start;i<candidates.size();i++) {
        if (candidates[i]>target) break;
        
        cand.push_back(candidates[i]);
        help(target-candidates[i],cand,res,candidates,i);
        cand.pop_back();
    }
}
