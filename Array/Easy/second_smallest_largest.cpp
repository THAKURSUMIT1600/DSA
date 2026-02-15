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

// Brute Force Approach: Sort the array and find second smallest and second largest
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) if sorting in-place
pair<int, int> findSecondSmallestLargestBruteForce(vector<int> &arr)
{
    if (arr.size() == 0 || arr.size() == 1)
    {
        return {-1, -1};
    }
    sort(arr.begin(), arr.end());
    return {arr[1], arr[arr.size() - 2]};
}

// Optimal Approach: Single pass to find both second smallest and second largest
// Time Complexity: O(n)
// Space Complexity: O(1)
pair<int, int> findSecondSmallestLargestOptimal(vector<int> &arr)
{
    if (arr.size() < 2)
        return {-1, -1};

    int maxfirst = INT_MIN, maxsecond = INT_MIN;
    int minfirst = INT_MAX, minsecond = INT_MAX;

    for (int x : arr)
    {
        // Largest (duplicates allowed)
        if (x >= maxfirst)
        {
            maxsecond = maxfirst;
            maxfirst = x;
        }
        else if (x > maxsecond)
        {
            maxsecond = x;
        }

        // Smallest (duplicates allowed)
        if (x <= minfirst)
        {
            minsecond = minfirst;
            minfirst = x;
        }
        else if (x < minsecond)
        {
            minsecond = x;
        }
    }

    return {minsecond, maxsecond};
}

int main()
{
    // Input array
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};

    // Brute Force
    vector<int> arrCopy1 = arr; // copy to avoid modifying original
    auto bruteResult = findSecondSmallestLargestBruteForce(arrCopy1);
    cout << "Brute Force - Second Smallest: " << bruteResult.first << ", Second Largest: " << bruteResult.second << endl;

    // Optimal Approach
    auto optimalResult = findSecondSmallestLargestOptimal(arr);
    cout << "Optimal Approach - Second Smallest: " << optimalResult.first << ", Second Largest: " << optimalResult.second << endl;

    return 0;
}