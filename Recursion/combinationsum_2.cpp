#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct CombinationSumII
{
    // Backtracking function
    void generate(vector<int> &nums,
                  int index,
                  int target,
                  vector<int> &current,
                  vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
            {
                continue;
            }
            if (nums[i] > target)
            {
                break;
            }

            current.push_back(nums[i]);
            generate(nums, i + 1, target - nums[i], current, result);
            current.pop_back();
        }
    }

    // Main logic function
    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        vector<int> current;

        sort(nums.begin(), nums.end());
        generate(nums, 0, target, current, result);
        return result;
    }
};

int main()
{
    CombinationSumII obj;

    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> answer = obj.combinationSum2(nums, target);

    // Printing result
    for (auto &vec : answer)
    {
        for (int num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}