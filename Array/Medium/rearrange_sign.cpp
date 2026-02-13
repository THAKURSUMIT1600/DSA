#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArrayBySign(vector<int> &A)
{
    vector<int> result(A.size());
    int pos = 0;
    int neg = 1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > 0)
        {
            result[pos] = A[i];
            pos += 2;
        }
        else if (A[i] < 0)
        {
            result[neg] = A[i];
            neg += 2;
        }
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter the Size of Array" << endl;
    cin >> n;

    vector<int> A(n);
    cout << "Enter the Elements of Array" << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> ans = rearrangeArrayBySign(A);
    cout << "Rearrange Element by Sign" << endl;
    for (int x : ans)
        cout << x << " ";

    return 0;
}
