#include "../Solutions.hpp"

using namespace std;

/***************** MedianOfTwoSortedArrays *****************/
/*
 There are two sorted arrays nums1 and nums2 of size m and n respectively.
 
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 
 Example 1:
 nums1 = [1, 3]
 nums2 = [2]
 
 The median is 2.0
 Example 2:
 nums1 = [1, 2]
 nums2 = [3, 4]
 
 The median is (2 + 3)/2 = 2.5
*/

double Solutions::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    priority_queue<int,vector<int>,greater<int>> high; //store large number part
    priority_queue<int,vector<int>,less<int>> low; //store small number part
    
    //if total number is odd, low has one number more.
    
    for (int num : nums1) {
        int highSize = high.size();
        int lowSize = low.size();
        if (lowSize==0) {
            low.push(num);
            continue;
        }
        if (lowSize==highSize) {
            //even
            if (num>low.top()) {
                high.push(num);
                low.push(high.top());
                high.pop();
            } else {
                low.push(num);
            }
        } else if (lowSize>highSize) {
            //odd
            if (num<=low.top()) {
                low.push(num);
                high.push(low.top());
                low.pop();
            } else {
                high.push(num);
            }
        }
    }
    
    for (int num : nums2) {
        int highSize = high.size();
        int lowSize = low.size();
        if (lowSize==0) {
            low.push(num);
            continue;
        }
        if (lowSize==highSize) {
            //even
            if (num>low.top()) {
                high.push(num);
                low.push(high.top());
                high.pop();
            } else {
                low.push(num);
            }
        } else if (lowSize>highSize) {
            //odd
            if (num<=low.top()) {
                low.push(num);
                high.push(low.top());
                low.pop();
            } else {
                high.push(num);
            }
        }
    }
    
    if (low.size()==high.size()) {
        return (double)low.top()/2+(double)high.top()/2;
    } else {
        return low.top();
    }
}
