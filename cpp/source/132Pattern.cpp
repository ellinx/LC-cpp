#include "../Solutions.hpp"
#include "main.h"

using namespace std;

/***************** 132 Pattern *****************/
/*
 Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.
 
 Note: n will be less than 15,000.
 
 Example 1:
 Input: [1, 2, 3, 4]
 
 Output: False
 
 Explanation: There is no 132 pattern in the sequence.
 Example 2:
 Input: [3, 1, 4, 2]
 
 Output: True
 
 Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
 Example 3:
 Input: [-1, 3, 2, 0]
 
 Output: True
 
 Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 */

//O(n) solution
bool Solutions::find132pattern(vector<int>& nums) {
    int n = nums.size();
    if (n<3) return false;
    vector<int> vec(n, nums[0]);
    stack<int> akStk;
    
    for (int i=1;i<n;i++) {
        vec[i] = min(vec[i-1], nums[i]);
    }
    printVector(vec);
    
    for (int i=n-1;i>0;i--) {
        if (nums[i]>vec[i-1]) {
            while (!akStk.empty() && akStk.top()<=vec[i-1]) {
                akStk.pop();
            }
            if (!akStk.empty() && akStk.top()<nums[i]) {
                return true;
            }
            akStk.push(nums[i]);
        }
        printStack(akStk);
    }
    return false;
}

//O(n^2) solution
bool find132pattern2(vector<int>& nums) {
    int n = nums.size();
    if (n<3) return false;
    vector<int> pattern(3,nums[0]);
    
    //pattern[0] is min of nums[0,j-1]
    for (int i=1;i<n-1;i++) {
        if (pattern[0] > nums[i-1]) {
            pattern[0] = nums[i-1];
            continue;
        }
        pattern[1] = nums[i];
        for (int j=i+1;j<n;j++) {
            if (nums[j]>pattern[0] && nums[j]<pattern[1]) {
                return true;
            }
        }
    }
    return false;
}

//O(n^3) solution
bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if (n<3) return false;
    vector<int> pattern(3,0);
    
    //check every possible pattern
    for (int i=0;i<n-2;i++) {
        pattern[0] = nums[i];
        for (int j=i+1;j<n-1;j++) {
            if (nums[i]<nums[j]) {
                pattern[1] = nums[j];
                for (int k=j+1;k<n;k++) {
                    if (nums[k]>pattern[0] && nums[k]<pattern[1]) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
