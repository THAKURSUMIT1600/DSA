#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<int> replaceWithRank(vector<int> &arr)
    {
        vector<int> res = arr;
        sort(res.begin(), res.end());
        unordered_map<int, int> st;
        int rank = 1;
        for (auto a : res)
        {
            if (st.find(a) == st.end())
            {
                st[a] = rank;
                rank++;
            }
        }

        for (auto &a : arr)
        {
            a = st[a];
        }
        return arr;
    }
};

int main()
{

    vector<int> arr = {20, 15, 26, 2, 98, 6};

    Solution obj;
    vector<int> result = obj.replaceWithRank(arr);

    // Print result
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}