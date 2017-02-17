#include "../Solutions.hpp"

using namespace std;

/***************** Merge Intervals *****************/
/*
 Given a collection of intervals, merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
*/
static bool CompInterval(Interval a, Interval b);

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    if (intervals.empty()) return res;
    sort(intervals.begin(),intervals.end(),CompInterval);
    int base=0;
    for (int i=1;i<intervals.size();i++) {
        if (intervals[base].end>=intervals[i].start) {
            intervals[base].end = max(intervals[base].end,intervals[i].end);
        } else {
            res.push_back(intervals[base]);
            base = i;
        }
    }
    res.push_back(intervals[base]);
    return res;
}

static bool CompInterval(Interval a, Interval b) {
    return (a.start<b.start);
}
