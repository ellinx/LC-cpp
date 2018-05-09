
#include "../Solutions.hpp"
#include "../Tester.hpp"

/***************** Find Right Interval *****************/
/*
 Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.
 
 For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.
 
 Note:
 You may assume the interval's end point is always bigger than its start point.
 You may assume none of these intervals have the same start point.
 
 Example 1:
 Input: [ [1,2] ]
 
 Output: [-1]
 
 Explanation: There is only one interval in the collection, so it outputs -1.
 
 Example 2:
 Input: [ [3,4], [2,3], [1,2] ]
 
 Output: [-1, 0, 1]
 
 Explanation: There is no satisfied "right" interval for [3,4].
 For [2,3], the interval [3,4] has minimum-"right" start point;
 For [1,2], the interval [2,3] has minimum-"right" start point.
 
 Example 3:
 Input: [ [1,4], [2,3], [3,4] ]
 
 Output: [-1, 2, -1]
 
 Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
 For [2,3], the interval [3,4] has minimum-"right" start point.
 */

vector<int> Solutions::findRightInterval(vector<Interval>& intervals) {
    vector<pair<int,int>> vec;
    vector<int> res(intervals.size(),0);
    for (int i=0;i<intervals.size();i++) {
        vec.push_back(pair<int,int>(intervals[i].start,i));
    }
    
    sort(vec.begin(), vec.end(), [](pair<int,int> a, pair<int,int> b){
        if (a.first == b.first)
            return a.second < b.second;
        else
            return a.first < b.first;
    });
    
//    for (auto each : vec) {
//        Tester::print(each.first);
//        Tester::print(each.second);
//    }
    
    for (int i=0;i<intervals.size();i++) {
        int cur = intervals[i].end;
        
        //use binary search to find the index of intervals which has min start greater than cur
        int index = -1;
        int start = 0;
        int end = vec.size()-1;
        while (start<=end) {
            if (start==end) {
                if (cur <= vec[start].first)
                    index = vec[start].second;
                
                break;
            }
            
            int mid = start + (end-start)/2;
//            cout<<"cur="<<cur<<", mid="<<mid<<endl;
            if (cur <= vec[mid].first) {
                index = vec[mid].second;
                end = mid-1;
            } else {
                start = mid+1;
            }
//            cout<<"index="<<index<<endl;
        }
        res[i] = index;
    }
    return res;
}
