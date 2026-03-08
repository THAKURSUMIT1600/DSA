#include <iostream>
#include <vector>
using namespace std;

void combinationSum(vector<int> &nums, int index, int target,
                    vector<int> &current,
                    vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }
    if (index == nums.size())
        return;

    // pick
    if (nums[index] <= target)
    {
        current.push_back(nums[index]);
        combinationSum(nums, index, target - nums[index], current, result);
        current.pop_back();
    }
    // no pick
    combinationSum(nums, index + 1, target, current, result);
}

int main()
{
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result;
    vector<int> current;

    combinationSum(nums, 0, target, current, result);
    cout << "Result : " << endl;
    // Printing result
    for (auto &comb : result)
    {
        for (auto &num : comb)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}