#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;

    int n = nums.size();
    int m = pow(2, n);
    for (int mask = 0; mask < m; mask++)
    {
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                result.push_back(nums[i]);
            }
        }
        ans.push_back(result);
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> result = subsets(nums);

    cout << "Subsets are:\n";

    for (auto subset : result)
    {
        cout << "{ ";
        for (auto x : subset)
        {
            cout << x << " ";
        }
        cout << "}\n";
    }

    return 0;
}