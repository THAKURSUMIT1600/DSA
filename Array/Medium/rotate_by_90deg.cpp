#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotateBetter(vector<vector<int>> &matrix)
{
    vector<vector<int>> result;
    int j = 0;
    while (j < matrix[0].size())
    {
        vector<int> val;
        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            val.push_back(matrix[i][j]);
        }
        result.push_back(val);
        j++;
    }
    return result;
}

vector<vector<int>> rotateOptimal(vector<vector<int>> &matrix)
{
    // transpose
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[0].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse
    for (int i = 0; i < matrix.size(); i++)
    {
        int start = 0;
        int end = matrix[0].size() - 1;
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
    return matrix;
}

void print(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<vector<int>> a = rotateBetter(matrix);
    print(a);
    vector<vector<int>> b = rotateOptimal(matrix);
    print(b);

    return 0;
}
