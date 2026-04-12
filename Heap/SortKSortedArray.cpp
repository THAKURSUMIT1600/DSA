#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sortKSortedArray(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pt;
    int n = arr.size();
    int index = 0;
    for (int i = 0; i <= k && i < n; i++)
    {
        pt.push(arr[i]);
    }

    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = pt.top();
        pt.pop();
        pt.push(arr[i]);
    }

    while (!pt.empty())
    {
        arr[index++] = pt.top();
        pt.pop();
    }
}

// ======================= MAIN =======================
int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    sortKSortedArray(arr, k);

    cout << "Sorted Array: ";
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}