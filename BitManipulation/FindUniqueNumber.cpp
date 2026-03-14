#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findUniqueNumbers(vector<int> &arr)
{
    int xorAll = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xorAll = xorAll ^ arr[i];
    }
    int rightMostBit = xorAll & (-xorAll);

    int x = 0;
    int y = 0;
    for (auto data : arr)
    {
        if (data & rightMostBit)
        {
            x = x ^ data;
        }
        else
        {
            y = y ^ data;
        }
    }
    if (x > y)
    {
        swap(x, y);
    }
    return {x, y};
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 2, 2};

    pair<int, int> ans = findUniqueNumbers(arr);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}