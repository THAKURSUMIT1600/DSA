#include <iostream>
#include <vector>
using namespace std;

int getfirst(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int index = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            index = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return index;
}

int getlast(vector<int> arr, int target)
{

    int low = 0;
    int high = arr.size() - 1;
    int index = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            index = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return index;
}

pair<int, int> firstLastOccurrence(vector<int> &arr, int target)
{
    int first = getfirst(arr, target);
    int last = getlast(arr, target);
    return {first, last};
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    pair<int, int> result = firstLastOccurrence(arr, target);

    cout << "First Occurrence Index: " << result.first << endl;
    cout << "Last Occurrence Index: " << result.second << endl;

    return 0;
}
