#include <iostream>
#include <vector>
using namespace std;

pair<int, int> floorCeilBrute(vector<int> &arr, int x)
{
    int floor = -1;
    int ceil = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= x)
        {
            floor = i;
        }
        if (arr[i] >= x)
        {
            ceil = i;
            return {floor, ceil};
        }
    }
    return {floor, ceil};
}
int getfloor(vector<int> arr, int x)
{
    int floor = -1;
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x)
        {
            floor = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return floor;
}
int getceil(vector<int> arr, int x)
{
    int ceil = -1;
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ceil = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ceil;
}

pair<int, int> floorCeilOptimal(vector<int> &arr, int x)
{
    int floor = getfloor(arr, x);
    int ceil = getceil(arr, x);
    return {floor, ceil};
}

int main()
{
    vector<int> arr = {1, 2, 4, 6, 8, 10};
    int x = 5;

    pair<int, int> bruteAns = floorCeilBrute(arr, x);
    pair<int, int> optimalAns = floorCeilOptimal(arr, x);

    cout << "Brute Result" << endl;
    cout << "Floor Index :" << bruteAns.first << " Floor Value :" << arr[bruteAns.first] << endl;
    cout << "Ceil Index :" << bruteAns.second << " Ceil Value :" << arr[bruteAns.second];
    cout << endl;
    cout << "Optimal Result" << endl;
    cout << "Floor Index :" << optimalAns.first << " Floor Value :" << arr[optimalAns.first] << endl;
    cout << "Ceil Index :" << optimalAns.second << " Ceil Value :" << arr[optimalAns.second];
    return 0;
}
