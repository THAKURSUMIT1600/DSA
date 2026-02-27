#include <iostream>
#include <vector>
using namespace std;

struct PeakFinder
{
    int findPeak1D(const vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return arr[mid];
            }
            else if (arr[mid] < arr[mid - 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }

    int maximum_element(vector<vector<int>> mat, int mid)
    {
        int maxrow = -1;
        int maxvalue = -1;
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][mid] > maxvalue)
            {
                maxvalue = mat[i][mid];
                maxrow = i;
            }
        }
        return maxrow;
    }

    pair<int, int> findPeak2D(const vector<vector<int>> &mat)
    {
        int low = 0;
        int high = mat[0].size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int maxrow = maximum_element(mat, mid);

            int left = (mid - 1 >= 0) ? mat[maxrow][mid - 1] : -1;
            int right = (mid + 1 < mat[0].size()) ? mat[maxrow][mid + 1] : -1;

            if (mat[maxrow][mid] > left && mat[maxrow][mid] > right)
            {
                return {maxrow, mid};
            }
            else if (left > mat[maxrow][mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};

int main()
{
    PeakFinder solver;

    vector<int> arr = {1, 3, 20, 4, 1};
    int peak1D = solver.findPeak1D(arr);
    cout << "1D Peak Index: " << peak1D << endl;

    vector<vector<int>> mat = {
        {1, 4, 3},
        {2, 9, 5},
        {3, 6, 7}};

    pair<int, int> peak2D = solver.findPeak2D(mat);
    cout << "2D Peak Position: ("
         << peak2D.first << ", "
         << peak2D.second << ")" << endl;

    return 0;
}