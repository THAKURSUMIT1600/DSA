#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int removeDuplicatesBrute(int arr[], int n)
{
    set<int> unique;
    for (int i = 0; i < n; i++)
    {
        unique.insert(arr[i]);
    }
    int i = 0;
    for (auto a = unique.begin(); a != unique.end(); a++)
    {
        arr[i] = *a;
        i++;
    }

    return unique.size();
}

int removeDuplicatesOptimal(int arr[], int n)
{
    int i = 0;
    int j = 1;
    while (j < n)
    {
        if (arr[i] == arr[j])
        {
            j++;
        }
        else
        {
            i++;
            arr[i] = arr[j];
            j++;
        }
    }
    return i + 1;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    if (n == 0)
    {
        cout << "Empty array!" << endl;
        return 0;
    }

    int arr[n], arr2[n];

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr2[i] = arr[i]; // copy for second test
    }

    int k1 = removeDuplicatesBrute(arr, n);
    cout << "\nAfter Brute Force (first " << k1 << " elements): ";
    for (int i = 0; i < k1; i++)
        cout << arr[i] << " ";

    int k2 = removeDuplicatesOptimal(arr2, n);
    cout << "\nAfter Optimal (first " << k2 << " elements): ";
    for (int i = 0; i < k2; i++)
        cout << arr2[i] << " ";

    return 0;
}
