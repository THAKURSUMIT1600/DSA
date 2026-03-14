#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findElement(vector<int> &arr)
    {
        int result = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            result = result ^ arr[i];
        }
        return result;
    }
};

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    int result = obj.findElement(arr);

    cout << "Element appearing once: " << result << endl;

    return 0;
}