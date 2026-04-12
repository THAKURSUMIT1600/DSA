#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{

    unordered_map<int, int> mp;
    for (auto a : tasks)
    {
        mp[a]++;
    }

    int maxfreq = 0;
    for (auto a : mp)
    {
        maxfreq = max(maxfreq, a.second);
    }
    int maxcount = 0;
    for (auto a : mp)
    {
        if (a.second == maxfreq)
            maxcount++;
    }

    int mininterval = max((int)tasks.size(), (maxfreq - 1) * (n + 1) + maxcount);
}

int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'C'};
    int n = 2;

    cout << "Minimum intervals required: " << leastInterval(tasks, n) << endl;

    return 0;
}