
/******* Find K Pairs With Smallest Sums *************/
/*
 You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 
 Define a pair (u,v) which consists of one element from the first array and one element from the second array.
 
 Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 
 Example 1:
 Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 
 Return: [1,2],[1,4],[1,6]
 
 The first 3 pairs are returned from the sequence:
 [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 
 Example 2:
 Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 
 Return: [1,1],[1,1]
 
 The first 2 pairs are returned from the sequence:
 [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 
 Example 3:
 Given nums1 = [1,2], nums2 = [3],  k = 3
 
 Return: [1,3],[2,3]
 
 All possible pairs are returned from the sequence:
 [1,3],[2,3]
 */

#include "../Solutions.hpp"

class MyCmp {
public:
    bool operator()(pair<pair<int,int>, int>& a, pair<pair<int,int>, int>& b) {
        return a.second>=b.second;
    }
};

vector<pair<int, int>> Solutions::kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int,int>> res;
    if (nums1.empty() || nums2.empty()) return res;
    
    priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>,int>>, MyCmp> minHeap;
    for (int i=0;i<nums1.size();i++) {
        pair<pair<int,int>, int> item;
        item.first = pair<int,int>(i,0);
        item.second = nums1[i]+nums2[0];
        minHeap.push(item);
    }
    
    while (!minHeap.empty()) {
        pair<pair<int,int>, int> item = minHeap.top();
        minHeap.pop();
        
        int index1 = item.first.first;
        int index2 = item.first.second;
        res.push_back(pair<int, int>(nums1[index1], nums2[index2]));
        if (res.size()==k) break;
        
        index2++;
        if (index2<nums2.size()) {
            item.first = pair<int,int>(index1, index2);
            item.second = nums1[index1]+nums2[index2];
            minHeap.push(item);
        }
    }
    return res;
}
