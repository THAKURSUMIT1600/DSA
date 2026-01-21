#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Binary Search Algorithm Summary:

Binary search is a search algorithm that finds the position of a target value within a sorted array
by repeatedly dividing the search interval in half.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int firstOccurrence(const vector<int>& arr, int value) {
    int low = 0, high = arr.size() - 1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value) {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] > value)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (ans != -1) {
        cout << "First Occurrence at Index : " << ans << endl;
    }
    return ans;
}

int lastOccurrence(const vector<int>& arr, int value) {
    int low = 0, high = arr.size() - 1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value) {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > value)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (ans != -1) {
        cout << "Last Occurrence at Index : " << ans << endl;
    }
    return ans;
}

void normalBinarySearch(const vector<int>& arr, int value) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value) {
            cout << "Element Found at Index : " << mid << endl;
            return;
        }
        else if (arr[mid] > value)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << "Element not found" << endl;
}


void binarysearch(vector<int> &arr, int value)
{
   int first = firstOccurrence(arr, value);
   if (first == -1) {
       cout << "Element not found" << endl;
       return;
   }
   
   int last = lastOccurrence(arr, value);
   
   for (int i = first; i <= last; i++) {
       cout << "Element Found at Index : " << i << endl;
   }
}

int main()
{
    cout << "Welcome to Binary Search Program\n";

    vector<int> arr;
    int n;

    cout << "Enter the Sorted Array Size: ";
    cin >> n;

    cout << "Enter the Sorted Array Elements:\n";
    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter element " << i << ": ";
        cin >> value;
        arr.push_back(value);
    }

    cout << "Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int value;
    cout << "Enter the Element to Searched :";
    cin >> value;
    binarysearch(arr, value);

    return 0;
}
