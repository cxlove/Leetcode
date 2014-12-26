# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e
def merge (intervals):
    n = len (intervals)
        if n == 0 : return []
        intervals.sort (lambda p , q : cmp (p.start , q.start))
        ans = [intervals[0]]
        for i in range (1 , n) :
            if intervals[i].start <= ans[-1].end :
                ans[-1].end = max (ans[-1].end , intervals[i].end)
            else :
                ans.append (intervals[i])
    return ans
class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        intervals.append (newInterval)
        return merge (intervals)