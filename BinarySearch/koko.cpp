#include <iostream>
#include <vector>
using namespace std;

long long calculateHours(vector<int> &piles, int speed)
{
    int sum = 0;
    for (auto a : piles)
    {
        sum += a / speed;
        if (a % speed != 0)
        {
            sum += 1;
        }
    }
    return sum;
}

int koko(vector<int> &piles, int H)
{
    int maxvalue = *max_element(piles.begin(), piles.end());
    int low = 1;
    int ans = -1;
    int high = maxvalue;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (calculateHours(piles, mid) <= H)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the Value of Piles Size" << endl;
    cin >> n;

    vector<int> piles(n);
    cout << "Enter the Piles Values :" << endl;
    for (int i = 0; i < n; i++)
        cin >> piles[i];

    int H;
    cout << "Enter the Value of H " << endl;
    cin >> H;
    cout << "Result : ";
    cout << koko(piles, H);

    return 0;
}