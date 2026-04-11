#include <iostream>
#include <vector>
using namespace std;

bool heapCheck(vector<int> &nums)
{
    int n = nums.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && nums[left] < nums[i])
            return false;
        if (right < n && nums[right] < nums[i])
            return false;
    }
    return true;
}

int main()
{
    vector<int> nums = {10, 20, 30, 21, 23};

    if (heapCheck(nums))
    {
        cout << "True: It is a Min Heap" << endl;
    }
    else
    {
        cout << "False: Not a Min Heap" << endl;
    }

    return 0;
}