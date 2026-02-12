#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Sorting-based approach
    int longestConsecutiveBetter(vector<int> &a)
    {
        if (a.empty())
            return 0;

        sort(a.begin(), a.end());
        int maxcount = 1; // at least 1
        int count = 1;

        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] == a[i - 1])
                continue;
            else if (a[i] == a[i - 1] + 1)
                count++;
            else
                count = 1;

            maxcount = max(maxcount, count);
        }
        return maxcount;
    }

    // HashSet-based optimal approach
    int longestConsecutiveOptimal(vector<int> &a)
    {
        if (a.empty())
            return 0;

        unordered_set<int> st(a.begin(), a.end());
        int maxcount = 0;

        for (auto x : st)
        {
            if (st.find(x - 1) == st.end())
            {
                int curr = x;
                int count = 1;

                while (st.find(curr + 1) != st.end())
                {
                    curr++;
                    count++;
                }
                maxcount = max(maxcount, count);
            }
        }

        return maxcount;
    }
};

int main()
{
    vector<int> a = {100, 4, 200, 1, 3, 2};

    Solution sol;

    int ans1 = sol.longestConsecutiveBetter(a);
    cout << "Better approach answer: " << ans1 << "\n";

    int ans2 = sol.longestConsecutiveOptimal(a);
    cout << "Optimal approach answer: " << ans2 << "\n";

    return 0;
}
