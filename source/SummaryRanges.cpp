/***************** Summary Ranges *****************/
/*
 Given a sorted integer array without duplicates, return the summary of its ranges.
 
 Example 1:
 Input: [0,1,2,4,5,7]
 Output: ["0->2","4->5","7"]
 Example 2:
 Input: [0,2,3,4,6,8,9]
 Output: ["0","2->4","6","8->9"]
 */

#include "../Solutions.hpp"

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    pair<int,int> range;
    
    if (nums.empty()) return res;
    range.first = nums[0];
    for (int i=1;i<nums.size();i++) {
        if (nums[i]!=nums[i-1]+1) {
            range.second = nums[i-1];
            if (range.first==range.second) {
                res.push_back(to_string(range.first));
            } else {
                string s = to_string(range.first);
                s += "->";
                s += to_string(range.second);
                res.push_back(s);
            }
            range.first = nums[i];
        }
    }
    range.second = nums.back();
    if (range.first==range.second) {
        res.push_back(to_string(range.first));
    } else {
        string s = to_string(range.first);
        s += "->";
        s += to_string(range.second);
        res.push_back(s);
    }
    return res;
}
