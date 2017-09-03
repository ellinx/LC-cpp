#include "../Solutions.hpp"

using namespace std;

/***************** Longest Harmonious Subsequence *****************/
/*
 We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
 
 Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
 
 Example 1:
 Input: [1,3,2,2,5,2,3,7]
 Output: 5
 Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 Note: The length of the input array will not exceed 20,000.
 */

int Solutions::findLHS(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    sort(nums.begin(), nums.end());
    vector<pair<int,int>> mem;
    pair<int,int> numNSize;
    for (int i=0;i<nums.size();i++) {
        if (i==0) {
            numNSize.first = nums[i];
            numNSize.second = 1;
        } else {
            if (nums[i]==nums[i-1]) {
                numNSize.second++;
            } else {
                mem.push_back(numNSize);
                numNSize.first = nums[i];
                numNSize.second = 1;
            }
        }
    }
    mem.push_back(numNSize);
    
    if (mem.size()==1) return 0;
    
    int res = 0;
    for (int i=1;i<mem.size();i++) {
        if (mem[i].first == mem[i-1].first+1) {
            res = max(res, mem[i].second+mem[i-1].second);
        }
    }
    return res;
}
