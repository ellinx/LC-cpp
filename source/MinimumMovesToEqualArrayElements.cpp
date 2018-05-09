
#include "../Solutions.hpp"

/***************** Minimum Moves To Equal Array Elements *****************/
/*
 Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
 
 Example:
 
 Input:
 [1,2,3]
 
 Output:
 3
 
 Explanation:
 Only three moves are needed (remember each move increments two elements):
 
 [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 */

int Solutions::minMoves(vector<int>& nums) {
    //increment n-1 elments by 1  <=> decrease 1 element by 1
    int res = 0;
    int min = nums[0];
    for (int i=1;i<nums.size();i++) {
        if (min > nums[i]) {
            min = nums[i];
        }
    }
    
    for (int num : nums) {
        res += num-min;
    }
    return res;
}

/***************** Minimum Moves To Equal Array Elements II *****************/
/*
 Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
 
 You may assume the array's length is at most 10,000.
 
 Example:
 
 Input:
 [1,2,3]
 
 Output:
 2
 
 Explanation:
 Only two moves are needed (remember each move increments or decrements one element):
 
 [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 */

int Solutions::minMoves2(vector<int>& nums) {
    int res = 0;
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size()-1;
    while (left<right) {
        res += nums[right]-nums[left];
        left++;
        right--;
    }
    return res;
}
