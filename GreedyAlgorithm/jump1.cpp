#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool jump(vector<int> &nums)
{

    int maxindex = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > maxindex)
        {
            return false;
        }
        maxindex = max(maxindex, i + nums[i]);
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    bool result = jump(nums);

    if (result)
    {
        cout << "True - Can reach last index" << endl;
    }
    else
    {
        cout << "False - Cannot reach last index" << endl;
    }

    return 0;
}