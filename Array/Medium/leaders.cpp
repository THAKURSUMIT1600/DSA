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

vector<int> findLeaders(vector<int> &arr)
{
    vector<int> leaders;
    int n = arr.size() - 1;
    leaders.push_back(arr[n]);
    int max = arr[n];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            leaders.push_back(arr[i]);
            max = arr[i];
        }
    }
    reverse(leaders.begin(), leaders.end());

    return leaders;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};

    vector<int> result = findLeaders(arr);

    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}
