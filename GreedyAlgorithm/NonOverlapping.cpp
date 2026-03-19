#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct Interval
{
    int start;
    int end;
};

bool comparator(Interval a, Interval b)
{
    if (a.end == b.end)
    {
        return a.start < b.start;
    }
    return a.end < b.end;
}
int eraseOverlapIntervals(vector<Interval> &intervals)
{
    if (intervals.size() == 0)
        return 0;
    sort(intervals.begin(), intervals.end(), comparator);
    int lastelem = intervals[0].end;
    int remove = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].start >= lastelem)
        {
            lastelem = intervals[i].end;
        }
        else
        {
            remove++;
        }
    }
    return remove;
}

int main()
{
    int n;
    cin >> n;

    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i].start >> intervals[i].end;
    }

    int result = eraseOverlapIntervals(intervals);
    cout << result << endl;

    return 0;
}