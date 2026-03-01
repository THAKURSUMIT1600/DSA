#include <iostream>
#include <vector>
using namespace std;

struct MatrixSearcher
{
    bool binarysearch(vector<int> mat, int target)
    {
        int start = 0;
        int end = mat.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mat[mid] == target)
            {
                cout << "Found at Col :" << mid << endl;
                return true;
            }
            else if (mat[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(const vector<vector<int>> &mat, int target)
    {
        for (int i = 0; i < mat.size(); i++)
        {
            int lastindex = mat[i].size() - 1;
            if (mat[i][0] <= target && mat[i][lastindex] >= target)
            {

                bool result = binarysearch(mat[i], target);
                if (result)
                {
                    cout << "Found at Row :" << i << endl;
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target = 34;

    MatrixSearcher searcher;

    bool found = searcher.searchMatrix(mat, target);

    if (found)
        cout << "Target found" << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}