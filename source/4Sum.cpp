#include "../Solutions.hpp"
#include "../Tester.hpp"

/***************** 4 Sum *****************/
/*
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 
 Note: The solution set must not contain duplicate quadruplets.
 
 For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 
 A solution set is:
 [
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
 ]
 */



vector<vector<int>> Solutions::fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    if (n < 4) return res;
    sort(nums.begin(),nums.end());
    Tester::print(nums);
    for (int i=0;i<n-3;i++) {
        if (i>0 && nums[i-1]==nums[i]) continue;
        if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
        if (nums[n-4]+nums[n-3]+nums[n-2]+nums[n-1]<target) break;
        
        for (int j=i+1;j<nums.size()-2;j++) {
            if (j>i+1 && nums[j-1]==nums[j]) continue;
            if (nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
            if (nums[n-4]+nums[n-3]+nums[n-2]+nums[n-1]<target) break;
            
            int left = j+1;
            int right = n-1;
            while (left<right) {
                int sum = nums[i]+nums[j]+nums[left]+nums[right];
                if(sum < target) {
                    left++;
                } else if(sum > target) {
                    right--;
                } else {
                    res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                    do{left++;}while(nums[left]==nums[left-1]&&left<right);
                    do{right--;}while(nums[right]==nums[right+1]&&left<right);
                }
            }
        }
    }
    return res;
}


/***************** 4 Sum II *****************/
/*
 Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 
 To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
 
 Example:
 
 Input:
 A = [ 1, 2]
 B = [-2,-1]
 C = [-1, 2]
 D = [ 0, 2]
 
 Output:
 2
 
 Explanation:
 The two tuples are:
 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 */

int Solutions::fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> mp;
    int res = 0;
    
    for (int a : A) {
        for (int b : B) {
            int sum = a+b;
            if (mp.find(sum)==mp.end()) {
                mp[sum] = 1;
            } else {
                mp[sum]++;
            }
        }
    }
    
    for (int c : C) {
        for (int d : D) {
            int sum = c+d;
            if (mp.find(-sum)!=mp.end()) {
                res += mp[-sum];
            }
        }
    }
    return res;
}
