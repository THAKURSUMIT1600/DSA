#include <iostream>
#include <vector>
using namespace std;

// Approach 1 - Counting Method
void sortColorsCounting(vector<int> &nums)
{
    int zero = 0;
    int one = 0;
    int two = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zero++;
        }
        else if (nums[i] == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (zero > 0)
        {
            nums[i] = 0;
            zero--;
        }
        else if (one > 0)
        {
            nums[i] = 1;
            one--;
        }
        else if (two > 0)
        {
            nums[i] = 2;
            two--;
        }
    }
}

// Approach 2 - Dutch National Flag (Optimal)
void sortColorsOptimal(vector<int> &nums)
{
    int left = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[left], nums[mid]);
            left++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (only 0,1,2): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Call any one approach
    // sortColorsCounting(nums);
    sortColorsOptimal(nums);

    cout << "Sorted array: ";
    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}
