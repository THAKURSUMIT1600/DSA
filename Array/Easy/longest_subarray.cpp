#include <iostream>
using namespace std;

int longestSubarrayWithSumK(int arr[], int n, int k)
{
    int left = 0;
    int right = 0;
    int sum = 0;
    int maxsub = 0;
    while (right < n)
    {
        sum += arr[right];
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxsub = max(maxsub, right - left + 1);
        }
        right++;
    }
    return maxsub;
}

int main()
{
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter value of k: ";
    cin >> k;

    int arr[n];

    cout << "Enter elements (positive integers): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = longestSubarrayWithSumK(arr, n, k);
    cout << "Maximum Subarray with Sum " << ans << endl;

    return 0;
}
