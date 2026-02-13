#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

class Solution
{
public:
    void generatepermutation(vector<int> nums, int index, vector<vector<int>> &arr)
    {
        if (index == nums.size())
        {
            arr.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            generatepermutation(nums, index + 1, arr);
            swap(nums[i], nums[index]);
        }
    }
    vector<int> nextPermutationBrute(vector<int> nums)
    {
        // find all permutation
        vector<vector<int>> arr;
        vector<int> original = nums;
        generatepermutation(nums, 0, arr);
        // sort
        sort(arr.begin(), arr.end());

        // find exact and next permutation
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == original)
            {
                if (i + 1 == arr.size())
                {
                    return arr[0];
                }
                else
                {
                    return arr[i + 1];
                }
            }
        }
        return {};
    }

    void nextPermutationOptimal(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i >= 0)
        {
            int j = n - 1;
            while (nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 3, 2};
    vector<int> nums2 = nums1;

    // Test Brute Force
    vector<int> resultBrute = sol.nextPermutationBrute(nums1);
    cout << "Brute Force Result: ";
    for (int x : resultBrute)
        cout << x << " ";
    cout << endl;

    // Test Optimal
    sol.nextPermutationOptimal(nums2);
    cout << "Optimal Result: ";
    for (int x : nums2)
        cout << x << " ";
    cout << endl;

    return 0;
}
