#include <iostream>
#include <cmath>
using namespace std;

int findNthRoot(int N, int M)
{
    int low = 1;
    int high = M;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long value = pow(mid, N);

        if (value == M)
            return mid;
        else if (value > M)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int N, M;
    cout << "Enter N : ";
    cin >> N;
    cout << "Enter M : ";
    cin >> M;

    int result = findNthRoot(N, M);
    cout << result;

    return 0;
}
