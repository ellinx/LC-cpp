#include "../Solutions.hpp"

using namespace std;

/***************** Kth Largest In Array *****************/

/*
 Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 
 For example,
 Given [3,2,1,5,6,4] and k = 2, return 5.
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

static bool comp(int a, int b);

int Solutions::findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,function<bool(int,int)>> pq(comp);
    for (int i=0;i<nums.size();i++) {
        pq.push(nums[i]);
        if (pq.size()>k) pq.pop();
    }
    return pq.top();
}

static bool comp(int a, int b) {
    return a>=b;
}
