#include <iostream>
#include <vector>
using namespace std;

int maxProfitBrute(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;
    int maxprofit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            int profit = prices[j] - prices[i];
            if (maxprofit < profit)
            {
                maxprofit = profit;
            }
        }
    }
    return maxprofit;
}

int maxProfitOptimal(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;
    int minvalue = prices[0];
    int maxprofit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int profit = prices[i] - minvalue;
        if (prices[i] < minvalue)
        {
            minvalue = prices[i];
        }
        if (profit > maxprofit)
        {
            maxprofit = profit;
        }
    }
    return maxprofit;
}

int main()
{
    int n;
    cout << "Enter the Size of Array" << endl;
    cin >> n;
    cout << "Enter the Values" << endl;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    cout << "Brute Profit: " << maxProfitBrute(prices) << endl;
    cout << "Optimal Profit: " << maxProfitOptimal(prices) << endl;

    return 0;
}
