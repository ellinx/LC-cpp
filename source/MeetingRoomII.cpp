#include "../Solutions.hpp"

using namespace std;

/***************** Meeting Room II *****************/

/*
 
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] find the minimum number of conference rooms required.
 
*/

int Solutions::minMeetingRooms(vector<Interval>& intervals) {
    int res = 0;
    int roomCounter =0;
    vector<int> start;
    vector<int> end;
    for (int i=0; i<intervals.size();i++) {
        start.push_back(intervals[i].start);
        end.push_back(intervals[i].end);
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    int index1=0;
    int index2=0;
    while (index1<start.size() && index2<end.size()) {
        if (start[index1] < end[index2]) {
            index1++;
            roomCounter++;
            if (res<roomCounter) res = roomCounter;
        } else if (start[index1] > end[index2]) {
            index2++;
            roomCounter--;
        } else {
            index1++;
            index2++;
        }
    }
    return res;
}
