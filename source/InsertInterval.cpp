#include "../Solutions.hpp"

using namespace std;

/***************** Insert Interval *****************/
/*
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 
 You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

vector<Interval> Solutions::insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    if (intervals.empty()) {
        res.push_back(newInterval);
        return res;
    }
    
    int index = 0;
    //add non-overlap
    while (index<intervals.size() && intervals[index].end < newInterval.start) {
        res.push_back(intervals[index]);
        index++;
    }
    //merge overlap
    while (index<intervals.size() && intervals[index].start <= newInterval.end) {
        newInterval.start = min(intervals[index].start,newInterval.start);
        newInterval.end = max(intervals[index].end,newInterval.end);
        index++;
    }
    res.push_back(newInterval);
    //add rest non-overlap
    while (index<intervals.size()) {
        res.push_back(intervals[index++]);
    }
    return res;
}
