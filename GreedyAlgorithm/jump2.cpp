#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jumps = 0;
        int currentend = 0;
        int farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);

            if (i == currentend)
            {
                jumps++;
                currentend = farthest;
            }
        }
        return jumps;
    }
};

int main()
{
    int n;
    cin >> n; // size of array

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // input elements
    }

    Solution sol;
    int result = sol.jump(nums);

    cout << result << endl;

    return 0;
}