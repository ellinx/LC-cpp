#include "Solution.hpp"
using namespace std;

/**************** Intersection of Two Arrays *********************/
/*
 Given two arrays, write a function to compute their intersection.

 Example:
 Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/

vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> res;
    int index1 = 0;
    int index2 = 0;
    while ((index1 < nums1.size()) && (index2 < nums2.size())) {
        if (nums1[index1] < nums2[index2]) {
            index1++;
        } else if (nums1[index1] > nums2[index2]) {
            index2++;
        } else {
            if (res.size() == 0) {
                res.push_back(nums1[index1]);
            }else if (res[res.size()-1] != nums1[index1]) {
                res.push_back(nums1[index1]);
            }
            index1++;
            index2++;
        }
    }

    return res;
}
