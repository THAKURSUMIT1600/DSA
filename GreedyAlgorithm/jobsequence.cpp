#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

class Solution
{
public:
    // You will write comparator
    static bool comparison(Job a, Job b)
    {
        return a.profit > b.profit;
    }

    // You will write full logic here
    pair<int, int> JobScheduling(Job arr[], int n)
    {

        sort(arr, arr + n, comparison);
        int maxindex = arr[0].dead;
        for (int i = 1; i < n; i++)
        {
            maxindex = max(maxindex, arr[i].dead);
        }
        vector<int> value(maxindex + 1, -1);
        int totalProfit = 0;
        int countjob = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (value[j] == -1)
                {
                    value[j] = i;
                    countjob++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {countjob, totalProfit};
    }
};

int main()
{
    int n = 4;

    Job arr[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 2, 40},
        {4, 2, 30}};

    Solution ob;

    pair<int, int> ans = ob.JobScheduling(arr, n);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}