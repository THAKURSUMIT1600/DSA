#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
    int start;
    int end;
};

vector<Interval> insertInterval(vector<Interval> &intervals, Interval newInterval)
{
    vector<Interval> result;
    int i = 0;
    int n = intervals.size();
    while (i < n && intervals[i].end < newInterval.start)
    {
        result.push_back(intervals[i]);
        i++;
    }

    while (i < n && intervals[i].start <= newInterval.end)
    {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
        i++;
    }
    result.push_back(newInterval);
    while (i < n)
    {
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}

int main()
{
    vector<Interval> intervals = {
        {1, 2},
        {3, 5},
        {6, 7},
        {8, 10}};

    Interval newInterval = {4, 8};

    vector<Interval> result = insertInterval(intervals, newInterval);

    for (auto &it : result)
    {
        cout << it.start << " " << it.end << endl;
    }

    return 0;
}