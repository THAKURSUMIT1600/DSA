#include <iostream>
#include <vector>
using namespace std;

int findMinimum(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};

    int result = findMinimum(arr);

    int low = 0;
    cout << "No of Times Rotated : " << result - low;
    return 0;
}
