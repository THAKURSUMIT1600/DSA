#include <iostream>
using namespace std;
void pascal(int n, int r, int c)
{
    vector<vector<int>> ps(n);

    for (int i = 0; i < n; i++)
    {
        ps[i].resize(i + 1);

        ps[i][0] = 1;
        ps[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            ps[i][j] = ps[i - 1][j - 1] + ps[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ps[i].size(); j++)
        {
            cout << ps[i][j];
        }
        cout << endl;
    }

    cout << "Value at r :" << r << " and c :" << c << " : " << ps[r][c];
}
int main()
{

    int n;
    cout << "Enter the value of n " << endl;
    cin >> n;

    int r;
    int c;
    cout << "Enter the Row and Col" << endl;
    cin >> r >> c;

    pascal(n, r, c);

    return 0;
}