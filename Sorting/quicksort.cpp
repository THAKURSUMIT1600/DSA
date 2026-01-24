#include <iostream>
#include <vector>
using namespace std;

/*
Quick Sort Algorithm Summary:

Quick sort is a divide-and-conquer sorting algorithm that selects a pivot element and partitions the array into two subarrays: elements less than the pivot and elements greater than the pivot. It recursively sorts the subarrays.

Time Complexity: O(n log n) on average, O(n²) in worst case (when the pivot is poorly chosen).
Space Complexity: O(log n) due to recursive stack space.
*/

// Hoare Partition
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];      // pivot = first element of subarray
    int start = low;
    int end = high;

    while (start < end) {
        while (start <= high && arr[start] <= pivot)
            start++;

        while (end >= low && arr[end] > pivot)
            end--;

        if (start < end)
            swap(arr[start], arr[end]);
    }

    swap(arr[low], arr[end]);  // place pivot in correct position
    return end;                // return pivot index
}

// Quick Sort
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main() {
    cout << "Welcome to Quick Sort Program\n";

    vector<int> arr;
    int n;

    cout << "Enter the Array Size: ";
    cin >> n;

    cout << "Enter the Array Elements:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter element " << i << ": ";
        cin >> value;
        arr.push_back(value);
    }

    cout << "Array Before Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    quicksort(arr, 0, n - 1);

    cout << "\nArray After Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
