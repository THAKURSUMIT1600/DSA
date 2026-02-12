#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateKOptimal(vector<int> &arr, int n, int k, bool rotateRight)
{

    if (k > n)
    {
        cout << "K cannot be greater than n";
    }
    else if (rotateRight)
    {
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
    }
    else if (!rotateRight)
    {
        reverse(arr.begin(), arr.end());
        int r = n - k;
        reverse(arr.begin(), arr.begin() + r);
        reverse(arr.begin() + r, arr.end());
    }
}

int main()
{
    int n, k;
    cout << "Enter size: ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    vector<int> arr2(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    // true  -> rotate right
    // false -> rotate left
    rotateKOptimal(arr2, n, k, true);

    for (int i = 0; i < n; i++)
    {
        cout << arr2[i];
    }
    return 0;
}
