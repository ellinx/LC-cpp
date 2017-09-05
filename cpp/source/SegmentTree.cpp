#include "../Solutions.hpp"
using namespace std;

/*************** Segment Tree **************/
/*
 We have an array arr[0 . . . n-1]. We should be able to
 1 Find the sum of elements from index l to r where 0 <= l <= r <= n-1
 
 2 Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1.
 */

int fillST(vector<int>& st, int index, int start, int end, vector<int>& nums);

//use array to store segment tree
vector<int> constructST(vector<int> nums) {
    int n = nums.size();
    int leaves = 1;
    while (leaves<n) {
        leaves *= 2;
    }
    vector<int> res(2*leaves-1, 0);
    fillST(res, 0, 0, n-1, nums);
    return res;
}

int fillST(vector<int>& st, int index, int start, int end, vector<int>& nums) {
    if (start==end) {
        st[index] = nums[start];
    } else {
        int mid = start + (end-start)/2;
        st[index] = fillST(st, 2*index+1, start, mid, nums) + fillST(st, 2*index+2, mid+1, end, nums);
    }
    return st[index];
}


