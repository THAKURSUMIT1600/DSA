#include <iostream>
using namespace std;

int findMissing(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] + 1 != arr[i])
        {
            return arr[i - 1] + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = -1;
    ans = findMissing(arr, n);
    if (ans == -1)
    {
        cout << "No Missing Number" << endl;
    }
    else
    {
        cout << "Missing Number : " << ans << endl;
    }
    return 0;
}
