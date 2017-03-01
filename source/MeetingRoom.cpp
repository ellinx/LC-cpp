#include "../Solutions.hpp"

using namespace std;

/***************** Meeting Room *****************/

/*
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings. For example, Given [[0, 30],[5, 10],[15, 20]], return false.
*/

static bool comp(Interval& in1, Interval& in2);

bool Solutions::canAttendMeetings(vector<Interval>& intervals) {
    if (intervals.empty()) return true;
    
    sort(intervals.begin(),intervals.end(),comp);
    int preEnd = intervals[0].end;
    for (int i=1; i<intervals.size(); i++) {
        if (preEnd > intervals[i].start) return false;
        else {
            preEnd = intervals[i].end;
        }
    }
    return true;
}

static bool comp(Interval& in1, Interval& in2) {
    return in1.start < in2.start;
}
