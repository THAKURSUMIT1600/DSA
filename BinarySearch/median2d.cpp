#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct MatrixMedian
{
    int median(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = INT_MAX;
        int high = INT_MIN;

        int desired = (m * n) / 2;

        // Find global min and max
        for (int i = 0; i < m; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n - 1]);
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i = 0; i < m; i++)
            {
                count += upper_bound(matrix[i].begin(),
                                     matrix[i].end(),
                                     mid) -
                         matrix[i].begin();
            }

            if (count <= desired)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};

    MatrixMedian obj;
    cout << "Median: " << obj.median(matrix) << endl;

    return 0;
}