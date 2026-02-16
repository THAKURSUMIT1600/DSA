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

int countOccurrences(vector<int> &arr, int target)
{
    int first = getfirst(arr, target);
    int last = getlast(arr, target);
    if (first == -1 && last == -1)
    {
        return 0;
    }
    return last - first + 1;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    int count = countOccurrences(arr, target);

    cout << "Count of Occurrences: " << count << endl;

    return 0;
}
