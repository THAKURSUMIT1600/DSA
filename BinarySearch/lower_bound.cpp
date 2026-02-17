#include <iostream>
#include <vector>
using namespace std;

int lowerBoundBrute(vector<int> &arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= x)
        {
            return i;
        }
    }
    return arr.size();
}

int lowerBoundOptimal(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int findindex = arr.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            findindex = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return findindex;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int x = 6;

    int bruteAns = lowerBoundBrute(arr, x);
    int optimalAns = lowerBoundOptimal(arr, x);

    cout << "Brute Lower Bound Index: " << bruteAns << endl;
    cout << "Optimal Lower Bound Index: " << optimalAns << endl;

    return 0;
}
