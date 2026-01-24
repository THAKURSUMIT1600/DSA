#include <iostream>
#include <vector>
using namespace std;

/*
Insertion Sort Algorithm Summary:

Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time by repeatedly inserting a new element into the sorted portion of the array.

Time Complexity: O(n^2) in worst and average cases, O(n) in best case (already sorted).
Space Complexity: O(1)
*/

void insertionsort(vector<int>& arr) {
    int n=arr.size();
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main() {
    cout << "Welcome to Insertion Sort Program\n";

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

    insertionsort(arr);

    cout << "\nArray After Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
