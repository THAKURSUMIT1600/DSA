#include <iostream>
using namespace std;

bool isOdd(int n)
{
    if (n & 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;

    cout << "Enter a non-negative integer: ";
    cin >> n;

    bool result = isOdd(n);

    if (result)
        cout << n << " is an ODD number." << endl;
    else
        cout << n << " is an EVEN number." << endl;

    return 0;
}