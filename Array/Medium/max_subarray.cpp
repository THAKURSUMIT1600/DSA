#include <iostream>
#include <vector>
using namespace std;

int maxSubarrayBrute(vector<int> &nums)
{
    int maxsubarray = INT_MIN;
    int startindex = 0;
    int endindex = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            if (sum > maxsubarray)
            {
                startindex = i;
                endindex = j;
                maxsubarray = sum;
            }
        }
    }
    cout << "Starting Index : " << startindex << endl;
    cout << "Ending Index :" << endindex << endl;
    return maxsubarray;
}

int maxSubarrayBetter(vector<int> &nums)
{
    int maxsubarray = INT_MIN;
    int startindex = 0;
    int endindex = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum > maxsubarray)
            {
                startindex = i;
                endindex = j;
                maxsubarray = sum;
            }
        }
    }
    cout << "Starting Index : " << startindex << endl;
    cout << "Ending Index :" << endindex << endl;
    return maxsubarray;
}

int maxSubarrayOptimal(vector<int> &nums)
{
    int currsum = nums[0];
    int maxsum = nums[0];
    int startindex = 0;
    int endindex = 0;
    int temp = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        // int p = currsum + nums[i];
        // currsum = max(nums[i], currsum + nums[i]);
        // maxsum = max(currsum, maxsum);
        if (currsum + nums[i] < nums[i])
        {
            currsum = nums[i];
            temp = i;
        }
        else
        {
            currsum += nums[i];
        }
        if (currsum > maxsum)
        {
            maxsum = currsum;
            startindex = temp;
            endindex = i;
        }
    }
    cout << "Starting Index : " << startindex << endl;
    cout << "Ending Index :" << endindex << endl;
    return maxsum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Brute Force: " << maxSubarrayBrute(nums) << endl;
    cout << "Better: " << maxSubarrayBetter(nums) << endl;
    cout << "Optimal: " << maxSubarrayOptimal(nums) << endl;

    return 0;
}
