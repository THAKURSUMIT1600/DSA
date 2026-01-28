#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 3, 5, 7, 8};
    int window = arr.size() + 1;
    int left = 0;
    int windowsum = 0;
    int target = 10;
    for (int right = 0; right < arr.size(); right++)
    {
        windowsum += arr[right];
        while (windowsum >= target)
        {
            window = min(window, right - left + 1);
            windowsum -= arr[left];
            left++;
        }
    }
    if (window == arr.size() + 1)
    {
        cout << "No Subarray Found" << endl;
    }
    else
    {
        cout << "Minimum Window Length Found is :" << window;
    }
    return 0;
}