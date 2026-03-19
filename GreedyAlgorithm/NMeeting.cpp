#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Meeting
{
    int start;
    int end;
    int pos;
};

bool comparator(Meeting a, Meeting b)
{
    if (a.end == b.end)
    {
        return a.start < b.start;
    }
    return a.end < b.end;
}

vector<int> nMeeting(vector<int> &start, vector<int> &end, int n)
{
    vector<int> result;
    vector<Meeting> mt;
    for (int i = 0; i < end.size(); i++)
    {
        mt.push_back({start[i], end[i], i + 1});
    }

    sort(mt.begin(), mt.end(), comparator);
    result.push_back(mt[0].pos);
    int lasttime = mt[0].end;

    for (int i = 1; i < mt.size(); i++)
    {
        if (mt[i].start > lasttime)
        {
            result.push_back(mt[i].pos);
            lasttime = mt[i].end;
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<int> start(n), end(n);

    // Input start times
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }

    // Input end times
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }

    // Function call
    vector<int> ans = nMeeting(start, end, n);

    // Output result
    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << endl;

    return 0;
}