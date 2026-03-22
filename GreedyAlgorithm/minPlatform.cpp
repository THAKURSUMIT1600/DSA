#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minPlatforms(vector<int> &arr, vector<int> &dep)
{

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0;
    int j = 0;
    int platform = 0;
    int maxplatform = 0;

    while (i < arr.size() && j < arr.size())
    {
        if (arr[i] <= dep[j])
        {
            platform++;
            i++;
        }
        else
        {
            platform--;
            j++;
        }

        maxplatform = max(platform, maxplatform);
    }
    return maxplatform;
}

int main()
{
    vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int> dep = {920, 1200, 1130, 1150, 1900, 2000};

    cout << minPlatforms(arr, dep);

    return 0;
}