#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &arr)
{
    int n = arr.size();
    int low = 1;      // avoid 0
    int high = n - 2; // avoid n-1

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check strict peak condition
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;

        // If increasing slope → move right
        else if (arr[mid] < arr[mid + 1])
            low = mid + 1;

        // If decreasing slope → move left
        else
            high = mid - 1;
    }

    return -1; // no strict peak found
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int index = findPeakElement(arr);

    if (index == -1)
        cout << "No strict peak found";
    else
        cout << "Peak index: " << index;

    return 0;
}
