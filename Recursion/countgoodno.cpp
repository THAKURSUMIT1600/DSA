#include <iostream>
using namespace std;

struct GoodNumbers
{
    static const long long MOD = 1000000007;

    long long myPow(long long x, long long n)
    {
        if (n == 0)
        {
            return 1;
        }

        if (n % 2 == 0)
        {
            long long half = myPow(x, n / 2);
            return (half * half) % MOD;
        }
        else
        {
            return (x % MOD * myPow(x, n - 1) % MOD) % MOD;
        }
    }

    long long countGoodNumbers(long long n)
    {
        long long evenpos = (n + 1) / 2;
        long long oddpos = n / 2;

        long long evenpow = myPow(5, evenpos);
        long long oddpow = myPow(4, oddpos);

        return (evenpow * oddpow) % MOD;
    }
};

int main()
{
    long long n;
    cin >> n;

    GoodNumbers obj;
    cout << obj.countGoodNumbers(n) << endl;

    return 0;
}