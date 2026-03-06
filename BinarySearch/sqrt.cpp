#include <iostream>
using namespace std;

long long sqrtBinarySearch(long long n)
{
    if (n < 2)
    {
        return n;
    }
    int low = 0;
    int high = n / 2;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    long long n;
    cout << "Enter a number: ";
    cin >> n;

    long long result = sqrtBinarySearch(n);

    cout << "Square root (floor value) is: " << result << endl;

    return 0;
}
