#include <iostream>
#include <vector>
using namespace std;

int binarySearchIterative(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
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
    return -1;
}

int binarySearchRecursive(vector<int> &arr, int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binarySearchRecursive(arr, low, mid - 1, target);
    }
    else
    {
        return binarySearchRecursive(arr, mid + 1, high, target);
    }
    return -1;
}

int main()
{

    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;

    // Iterative Call
    int index1 = binarySearchIterative(arr, target);

    // Recursive Call
    int index2 = binarySearchRecursive(arr, 0, arr.size() - 1, target);

    // Output (optional structure)
    if (index1 != -1)
        cout << "Iterative: Found at index " << index1 << endl;
    else
        cout << "Iterative: Not found" << endl;

    if (index2 != -1)
        cout << "Recursive: Found at index " << index2 << endl;
    else
        cout << "Recursive: Not found" << endl;

    return 0;
}
