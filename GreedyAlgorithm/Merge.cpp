#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());

        for (auto interval : intervals)
        {
            if (result.empty() || result.back()[1] < interval[0])
            {
                result.push_back(interval);
            }
            else
            {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = sol.merge(intervals);

    cout << "Merged Intervals: ";
    for (auto &interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    return 0;
}