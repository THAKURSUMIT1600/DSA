#include <iostream>
using namespace std;

int findSingleElement(int arr[], int n)
{
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = findSingleElement(arr, n);
    cout << "Element Occuring Once is : " << ans;
    return 0;
}
