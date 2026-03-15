#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    // if (n <= 0)
    //     return false;
    // while (n > 1)
    // {
    //     if (n % 2 != 0)
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         n = n / 2;
    //     }
    // }
    // return true;
    if (n <= 0)
        return false;
    int m = n - 1;
    if ((n & m) == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    bool result = isPowerOfTwo(n);

    if (result)
        cout << n << " is a power of 2." << endl;
    else
        cout << n << " is NOT a power of 2." << endl;

    return 0;
}