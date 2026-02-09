#include <iostream>
using namespace std;

int maxConsecutiveOnes(int arr[], int n)
{
    int maxx = 0;
    int cmax = 0;
    bool zero = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zero = true;
            maxx = max(cmax, maxx);
            cmax = 0;
        }
        else
        {
            cmax++;
        }
    }
    if (maxx == 0 && !zero)
    {
        return n;
    }
    return maxx;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements (only 0s and 1s): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = maxConsecutiveOnes(arr, n);
    cout << "Maximum Consecutive One :" << ans << endl;

    return 0;
}
