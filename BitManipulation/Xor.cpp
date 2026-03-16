#include <iostream>
using namespace std;

int XOR(int n)
{
    if (n % 4 == 0)
    {
        cout << "Value : " << n << endl;
        return n;
    }
    else if (n % 4 == 1)
    {
        cout << "Value : " << 1 << endl;
        return 1;
    }
    else if (n % 4 == 2)
    {
        cout << "Value : " << n + 1 << endl;
        return n + 1;
    }
    cout << "Value : " << 0 << endl;
    return 0;
}
// Write your function here
int findXOR(int L, int R)
{
    return XOR(L - 1) ^ XOR(R);
}

int main()
{
    int L, R;

    cout << "Enter L: ";
    cin >> L;

    cout << "Enter R: ";
    cin >> R;

    int ans = findXOR(L, R);

    cout << "XOR from " << L << " to " << R << " is: " << ans << endl;

    return 0;
}