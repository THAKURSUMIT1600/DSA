#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarraySumK(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int sum = 0;
    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxlen = max(maxlen, i + 1);
        }
        int rem = sum - k;
        if (mp.find(rem) != mp.end())
        {
            maxlen = max(maxlen, i - mp[rem]);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return maxlen;
}

int main()
{
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter value of k: ";
    cin >> k;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = longestSubarraySumK(arr, n, k);

    cout << "Length of longest subarray with sum " << k << " is: " << ans << endl;

    return 0;
}
