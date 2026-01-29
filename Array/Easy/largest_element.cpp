#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: Sort the array and return the last element
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) if sorting in-place
int findLargestBruteForce(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1];
}

// Optimal Approach: Linear scan to find the maximum element
// Time Complexity: O(n)
// Space Complexity: O(1)
int findLargestOptimal(vector<int> &arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    // Input array
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};

    // Brute Force
    vector<int> arrCopy = arr; // copy to avoid modifying original
    int bruteResult = findLargestBruteForce(arrCopy);
    cout << "Brute Force Result: " << bruteResult << endl;

    // Optimal
    int optimalResult = findLargestOptimal(arr);
    cout << "Optimal Result: " << optimalResult << endl;

    return 0;
}