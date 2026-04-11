#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 👉 You implement this
    void heapify(vector<int> &nums, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest])
        {
            largest = left;
        }
        if (right < n && nums[right] > nums[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }

    // 👉 You implement this
    vector<int> minToMaxHeap(vector<int> nums)
    {
        int n = nums.size();
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapify(nums, n, i);
        }
        return nums;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {10, 20, 30, 21, 23};

    vector<int> result = obj.minToMaxHeap(nums);

    cout << "Max Heap: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}