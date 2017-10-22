
#include "../Solutions.hpp"
#include "../Tester.hpp"

/***************** Queue Reconstruction By Height *****************/
/*
 Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 
 Note:
 The number of people is less than 1,100.
 
 Example
 
 Input:
 [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 
 Output:
 [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

class cmp{
public:
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        if (a.first!=b.first) return a.first<b.first;
        
        return a.second>b.second;
    }
};

vector<pair<int, int>> Solutions::reconstructQueue(vector<pair<int, int>>& people) {
    vector<pair<int, int>> res;
    if (people.empty()) return res;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> maxHeap;
    
    for (auto person : people) {
        maxHeap.push(person);
    }
    
    int maxHeight = maxHeap.top().first;
    while (!maxHeap.empty() && maxHeap.top().first == maxHeight) {
        pair<int,int> tmp = maxHeap.top();
        maxHeap.pop();
        res.push_back(tmp);
    }
    
    while (!maxHeap.empty()) {
        pair<int,int> tmp = maxHeap.top();
        maxHeap.pop();
        res.insert(res.begin()+tmp.second, tmp);
    }
    return res;
}
