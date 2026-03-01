#include <iostream>
#include <vector>
using namespace std;

struct MaxOnesRowFinder
{
    int findRowWithMaxOnes(const vector<vector<int>> &mat)
    {
        int maxonesrow = -1;
        int maxonescount = -1;
        for (int i = 0; i < mat.size(); i++)
        {
            int start = 0;
            int end = mat[i].size() - 1;
            int onestart = -1;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (mat[i][mid] == 1)
                {
                    onestart = mid;
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            cout << "One start for i:" << i << " : : " << onestart << endl;
            if (onestart != -1)
            {
                int count = mat[i].size() - onestart;
                cout << "Count :" << count << endl;
                if (count > maxonescount)
                {
                    maxonescount = count;
                    maxonesrow = i;
                }
            }
            else
            {
                cout << "Count :0" << endl;
            }
        }
        return maxonesrow;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0}};

    MaxOnesRowFinder finder;

    int result = finder.findRowWithMaxOnes(mat);

    cout << "Row with maximum 1's: " << result << endl;

    return 0;
}