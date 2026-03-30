#include <iostream>
#include <vector>
using namespace std;
void countSubsequenceSumK(vector<int> &nums, int index, int sum, int k, int &count)
{
    if (index == nums.size())
    {
        if (sum == k)
        {
            count++;
        }
        return;
    }
    sum += nums[index];
    countSubsequenceSumK(nums, index + 1, sum, k, count);
    sum -= nums[index];
    countSubsequenceSumK(nums, index + 1, sum, k, count);
}

int main()
{
    vector<int> nums = {1, 2, 1};
    int k = 2;
    int count = 0;
    countSubsequenceSumK(nums, 0, 0, k, count);
    cout << "Count: " << count;

    return 0;
}