#include <iostream>
using namespace std;

bool checkBit(int n, int i)
{
    auto res = (1 << i) & n;
    if (res != 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int n, i;

    cout << "Enter the number: ";
    cin >> n;

    cout << "Enter the bit index to check: ";
    cin >> i;

    bool result = checkBit(n, i);

    if (result)
        cout << "The " << i << "-th bit is SET." << endl;
    else
        cout << "The " << i << "-th bit is NOT SET." << endl;

    return 0;
}