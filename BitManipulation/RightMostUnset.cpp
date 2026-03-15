#include <iostream>
using namespace std;

int setRightmostUnsetBit(int n)
{
    return n | (n + 1);
}

int main()
{
    int n;
    cin >> n;

    int result = setRightmostUnsetBit(n);
    cout << result;

    return 0;
}