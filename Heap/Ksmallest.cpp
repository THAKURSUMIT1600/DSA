#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ======================= HEAP APPROACH (kth SMALLEST) =======================
int kthSmallest_heap(vector<int> &arr, int k)
{
    priority_queue<int> pt;

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

// ======================= MAIN FUNCTION =======================
int main()
{
    cout << "Kth Smallest Element Finder\n";

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

    // Edge case check
    if (k <= 0 || k > n)
    {
        cout << "Invalid k!" << endl;
        return 0;
    }

    int result = kthSmallest_heap(arr, k);

    cout << "Kth Smallest Element: " << result << endl;

    return 0;
}