#include <iostream>
#include <climits>
using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == divisor)
    {
        return 1;
    }

    bool sign = true;

    if (dividend < 0 && divisor >= 0)
        sign = false;

    if (dividend >= 0 && divisor < 0)
        sign = false;

    long n = abs((long)dividend);
    long d = abs((long)divisor);

    long quotient = 0;

    while (n >= d)
    {
        int count = 0;

        while (n >= (d << (count + 1)))
        {
            count++;
        }

        quotient += 1LL << count;
        n -= d << count;
    }

    if (quotient == (1LL << 31) && sign)
        return INT_MAX;

    if (quotient == (1LL << 31) && !sign)
        return INT_MIN;

    return sign ? quotient : -quotient;
}

int main()
{
    int dividend, divisor;
    cin >> dividend >> divisor;

    int result = divide(dividend, divisor);
    cout << result;

    return 0;
}