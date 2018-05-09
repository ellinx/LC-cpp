
#include "../Solutions.hpp"

/***************** Maximum XOR Of Two Numbers In An Array *****************/
/*
 Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 2^31.
 
 Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 
 Could you do this in O(n) runtime?
 
 Example:
 
 Input: [3, 10, 5, 25, 2, 8]
 
 Output: 28
 
 Explanation: The maximum result is 5 ^ 25 = 28.
 */

int Solutions::findMaximumXOR(vector<int>& nums) {
    int res = 0;
    int mask = 0;
    for (int i=31;i>=0;i--) {
        mask |= 1<<i;
        unordered_set<int> numSet;
        for (int num : nums) {
            numSet.insert(num&mask);
        }
        
        int next = res | (1<<i);
        for (int num : numSet) {
            if (numSet.find(next^num)!=numSet.end()) {
                res = next;
                break;
            }
        }
        
    }
    return res;
}
