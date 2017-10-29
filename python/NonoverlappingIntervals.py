"""
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
"""


# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

from Interval import *


class NonoverlappingIntervals:
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """

        if len(intervals)==0:
            return 0

        noOverlapping = 0
        intervals.sort(key=lambda interval : interval.end)
        # print(intervals)
        cur = intervals[0]
        noOverlapping += 1;
        for i in range(1,len(intervals)):
            if cur.end <= intervals[i].start:
                cur = intervals[i]
                noOverlapping += 1

        return len(intervals)-noOverlapping


# test
tmp = NonoverlappingIntervals()
intervals = [
    Interval(1,2),
    Interval(2,3),
    Interval(3,4),
    Interval(1,3)
]
result = tmp.eraseOverlapIntervals(intervals)
print(result)