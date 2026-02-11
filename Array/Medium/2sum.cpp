#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

string twoSumBruteVariant1(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return "True";
            }
        }
    }
    return "False";
}

vector<int> twoSumBruteVariant2(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

string twoSumBetterVariant1(vector<int> &arr, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        int req = target - arr[i];
        if (mp.find(req) != mp.end())
        {
            return "True";
        }
        mp[arr[i]] = i;
    }
    return "False";
}

vector<int> twoSumBetterVariant2(vector<int> &arr, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        int req = target - arr[i];
        if (mp.find(req) != mp.end())
        {
            return {mp[req], i};
        }
        mp[arr[i]] = i;
    }
    return {-1, -1};
}

string twoSumOptimalVariant1(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == target)
        {
            return "True";
        }
        else if (arr[left] + arr[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return "False";
}

vector<int> twoSumOptimalVariant2(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == target)
        {
            return {left, right};
        }
        else if (arr[left] + arr[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return {-1, -1};
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    cout << "\n===== RESULTS =====\n";

    cout << "Brute Variant 1: "
         << twoSumBruteVariant1(arr, target) << endl;

    vector<int> r1 = twoSumBruteVariant2(arr, target);
    cout << "Brute Variant 2: {" << r1[0] << ", " << r1[1] << "}\n";

    cout << "Better Variant 1: "
         << twoSumBetterVariant1(arr, target) << endl;

    vector<int> r2 = twoSumBetterVariant2(arr, target);
    cout << "Better Variant 2: {" << r2[0] << ", " << r2[1] << "}\n";

    cout << "Optimal Variant 1: "
         << twoSumOptimalVariant1(arr, target) << endl;

    vector<int> r3 = twoSumOptimalVariant2(arr, target);
    cout << "Optimal Variant 2: {" << r3[0] << ", " << r3[1] << "}\n";

    return 0;
}
