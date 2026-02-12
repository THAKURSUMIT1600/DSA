#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityBetter(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int mid = nums.size() / 2;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second > mid)
        {
            return i->first;
        }
    }
    return -1;
}
int majorityOptimal(vector<int> &nums)
{
    int count = 0, element = 0;

    for (int x : nums)
    {
        if (count == 0)
            element = x;

        count += (x == element) ? 1 : -1;
    }

    // 🔹 VERIFY if it's really majority
    count = 0;
    for (int x : nums)
        if (x == element)
            count++;

    if (count > nums.size() / 2)
        return element;
    else
        return -1;
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

    cout << "\n===== RESULTS =====\n";
    cout << "Majority (HashMap): " << majorityBetter(nums) << endl;
    cout << "Majority (Boyer-Moore): " << majorityOptimal(nums) << endl;

    return 0;
}
