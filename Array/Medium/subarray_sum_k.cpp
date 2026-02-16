#include <iostream>
#include <vector>
using namespace std;

void findAllSubarraysBrute(vector<int> &arr, int K)
{
    // solve for all kind of number
    int totalsubarray = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == K)
            {
                totalsubarray++;
            }
        }
    }
    cout << "Total Subarray :" << totalsubarray;
}

void findAllSubarraysOptimal(vector<int> &arr, int K)
{
    int left = 0;
    int right = 0;
    int subarray = 0;
    int sum = 0;
    while (right < arr.size())
    {
        sum += arr[right];
        while (sum > K)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == K)
        {
            subarray++;
        }
        right++;
    }
    cout << "Total Subarray" << subarray;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int K = 5;

    cout << "Brute Force Approach:\n";
    findAllSubarraysBrute(arr, K);

    cout << "\nOptimal Approach:\n";
    findAllSubarraysOptimal(arr, K);

    return 0;
}
