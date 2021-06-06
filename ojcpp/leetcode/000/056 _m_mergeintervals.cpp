//
// Created by Rui Zhou on 14/4/18.
//

/*
 * https://leetcode.com/problems/merge-intervals/description/
 * Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//合并重叠区间
#include <codech/codech_def.h>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if (intervals.empty())
            return ret;

        sort(intervals.begin(),intervals.end(), [](Interval &a, Interval &b){
            return a.start < b.start;
        });
        ret.push_back(intervals[0]);
        for (int i=1; i < intervals.size(); i++) {
            int  j = ret.size() -1;
            Interval &a = ret[j];
            Interval &b = intervals[i];

            if (b.start<=a.end && b.start>=a.start) {
                a.end = max(a.end,b.end);
            } else {
                ret.push_back(b);
            }
        }
        return ret;
    }
};


DEFINE_CODE_TEST(056_mergeintervals)
{
    Solution obj;
    {
        vector<Interval> v{{1,3},{2,6},{8,10},{15,18}};
        vector<Interval> ret = obj.merge(v);
        for (auto &iter : ret) {
            cout << iter.start << "," << iter.end << endl;
        }
    }
}