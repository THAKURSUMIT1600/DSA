#include <iostream>
#include <vector>
using namespace std;

struct RowColumnMatrixSearcher
{
    bool searchMatrix(const vector<vector<int>> &mat, int target)
    {
        int rowmax = mat.size();
        int colmax = mat[0].size();
        int row = 0;
        int col = mat[0].size() - 1;
        while (row < rowmax && col < colmax)
        {
            if (mat[row][col] == target)
            {
                cout << "Found at Row : " << row << " Found at Col :" << col << endl;
                return true;
            }
            else if (mat[row][col] < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}};

    int target = 13;

    RowColumnMatrixSearcher searcher;

    bool found = searcher.searchMatrix(mat, target);

    if (found)
        cout << "Target Found" << endl;
    else
        cout << "Target Not Found" << endl;

    return 0;
}