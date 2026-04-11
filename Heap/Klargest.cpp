#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Find Kth Largest Element in an Array

    Approaches:
    1. Sorting
    2. Heap (Priority Queue)
    3. QuickSelect
*/

// ======================= APPROACH 1: SORTING =======================
int kthLargest_sort(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1];
}

// ======================= APPROACH 2: HEAP =======================
int kthLargest_heap(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pt;
    for (auto a : arr)
    {

        pt.push(a);
        if (pt.size() > k)
        {
            pt.pop();
        }
    }
    return pt.top();
}

// ======================= APPROACH 3: QUICKSELECT =======================
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int start = low + 1;
    int end = high;

    while (start < end)
    {
        while (start <= high && arr[start] <= pivot)
        {
            start++;
        }
        while (end >= low && arr[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[end], arr[low]);
    return end;
}

int quickSelect(vector<int> &arr, int low, int high, int k)
{
    if (low <= high)
    {
        int p = partition(arr, low, high);
        if (p == k)
        {
            return arr[p];
        }
        else if (p > k)
        {
            return quickSelect(arr, low, p - 1, k);
        }
        else
        {
            return quickSelect(arr, p + 1, high, k);
        }
    }
    return -1;
}

int kthLargest_quickselect(vector<int> &arr, int k)
{
    int n = arr.size();
    int index = n - k;

    return quickSelect(arr, 0, n - 1, index);
}

// ======================= MAIN FUNCTION =======================
int main()
{
    cout << "Kth Largest Element Finder\n";

    int n, k;
    vector<int> arr;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "Enter value of k: ";
    cin >> k;

    // -------- Choose Approach --------
    int choice;
    cout << "\nChoose Approach:\n";
    cout << "1. Sorting\n";
    cout << "2. Heap\n";
    cout << "3. QuickSelect\n";
    cout << "Enter choice: ";
    cin >> choice;

    int result = -1;

    switch (choice)
    {
    case 1:
        result = kthLargest_sort(arr, k);
        break;

    case 2:
        result = kthLargest_heap(arr, k);
        break;

    case 3:
        result = kthLargest_quickselect(arr, k);
        break;

    default:
        cout << "Invalid choice!\n";
        return 0;
    }

    cout << "Kth Largest Element: " << result << endl;

    return 0;
}