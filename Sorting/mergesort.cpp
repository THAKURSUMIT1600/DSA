#include <iostream>
#include <vector>
using namespace std;

/*
Merge Sort Algorithm Summary:

Merge sort is a divide-and-conquer sorting algorithm that divides the array into two halves, recursively sorts each half, and then merges the two sorted halves into a single sorted array.

Time Complexity: O(n log n) in all cases.
Space Complexity: O(n) due to the temporary array used for merging.
*/

// Merge two sorted halves
void merge(vector<int>& arr, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    vector<int> temp;

    // Merge elements from both halves
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right half
    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy temp array back to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[low + k] = temp[k];
    }
}

// Merge Sort function
void mergesort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);      // Sort left half
        mergesort(arr, mid + 1, high); // Sort right half
        merge(arr, low, mid, high);    // Merge sorted halves
    }
}

// Driver code
int main() {
    cout << "Welcome to Merge Sort Program\n";

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
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergesort(arr, 0, n - 1);

    cout << "Array After Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
