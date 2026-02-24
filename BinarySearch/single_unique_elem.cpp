#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();

    // Edge cases
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1;
    int high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If element is unique
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        // Your parity logic
        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
            (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter sorted elements (every element twice except one): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int value = singleNonDuplicate(arr);

    if (value == -1)
        cout << "Element Does not Exist";
    else
        cout << "Single Unique Element is : " << value;

    return 0;
}
