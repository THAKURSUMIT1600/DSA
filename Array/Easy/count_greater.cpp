#include <iostream>
#include <vector>
using namespace std;

vector<int> countGreater(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                count++;
            }
        }

        result[i] = count;
    }

    return result;
}

int main()
{
    vector<int> arr = {4, 5, 2, 25, 7};

    vector<int> ans = countGreater(arr);

    cout << "Count of greater elements to the right: ";
    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}