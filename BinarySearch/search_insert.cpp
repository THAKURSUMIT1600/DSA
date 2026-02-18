#include <iostream>
#include <vector>
using namespace std;

int searchInsertBrute(vector<int> &arr, int x)
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

int searchInsertOptimal(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int index = arr.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            index = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {1, 3, 5, 6};
    int x = 5;

    int bruteAns = searchInsertBrute(arr, x);
    int optimalAns = searchInsertOptimal(arr, x);

    cout << "Brute Search Insert Position: " << bruteAns << endl;
    cout << "Optimal Search Insert Position: " << optimalAns << endl;

    return 0;
}
