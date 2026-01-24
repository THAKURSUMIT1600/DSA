#include <iostream>
#include <vector>
using namespace std;

/*
Bubble Sort Algorithm Summary:

Bubble sort is a simple sorting algorithm that repeatedly steps through the list,
compares adjacent elements and swaps them if they are in the wrong order.
The pass through the list is repeated until the list is sorted.

Time Complexity: O(n^2) in worst and average case, O(n) in best case (already sorted).
Space Complexity: O(1)
*/

void bubblesort(vector<int>& arr) {
    bool swapped;
    int n = arr.size();

    // Outer loop: perform passes until the array is sorted
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Inner loop: compare adjacent elements and swap if necessary
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no swaps occurred in this pass, the array is already sorted
        if (!swapped)
            break;
    }
}

int main() {
    cout << "Welcome to Bubble Sort Program\n";

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

    bubblesort(arr);

    cout << "\nArray After Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
