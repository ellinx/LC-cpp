
/***************** Top K Frequent Elements *****************/
/*
 Given a non-empty array of integers, return the k most frequent elements.
 
 For example,
 Given [1,1,1,2,2,3] and k = 2, return [1,2].
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

#include "../Solutions.hpp"
#include "../Tester.hpp"

class MyCmpPair {
public:
    bool operator()(pair<int,int> a, pair<int, int> b ) {
        return a.second<b.second;
    }
};

vector<int> Solutions::topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int,int>, vector<pair<int, int>>, MyCmpPair> pq;
    unordered_map<int, int> mp;
    vector<int> res;
    
    for (int i=0;i<nums.size();i++) {
        if (mp.find(nums[i])==mp.end()) {
            mp[nums[i]] = 1;
        } else {
            mp[nums[i]]++;
        }
    }
    
    for (auto iter = mp.begin();iter!=mp.end();iter++) {
        pq.push(pair<int,int>(*iter));
    }
    
    for (int i=0;i<k;i++) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}


