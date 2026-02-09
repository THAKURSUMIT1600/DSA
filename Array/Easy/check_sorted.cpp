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

bool isSortedBrute(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool isSortedOptimal(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    // Edge cases
    if (n == 0)
    {
        cout << "Empty array is considered sorted." << endl;
        return 0;
    }

    if (n == 1)
    {
        cout << "Single element array is always sorted." << endl;
        return 0;
    }

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool brute = isSortedBrute(arr, n);
    cout << "\nBrute Force Result: "
         << (brute ? "Sorted" : "Not Sorted") << endl;

    bool optimal = isSortedOptimal(arr, n);
    cout << "Optimal Result: "
         << (optimal ? "Sorted" : "Not Sorted") << endl;

    return 0;
}
