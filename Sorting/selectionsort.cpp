#include <iostream>
#include <vector>
using namespace std;

/*
Selection Sort Algorithm Summary:

Selection sort is a simple sorting algorithm that repeatedly selects the smallest element from the unsorted portion of the array and swaps it with the first unsorted element.

Time Complexity: O(n^2) in worst, average, and best cases.
Space Complexity: O(1)
*/

void selectionsort(vector<int>& arr) {
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[minindex]>arr[j]){
                minindex=j;
            }
        }
        if(minindex!=i){
            swap(arr[minindex],arr[i]);
        }
    }
}

int main() {
    cout << "Welcome to Selection Sort Program\n";

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

    selectionsort(arr);

    cout << "\nArray After Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
