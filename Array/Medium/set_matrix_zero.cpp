#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> setZeroesBetter(vector<vector<int>> &matrix)
{
    vector<int> row;
    vector<int> col;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row.push_back(i);
                col.push_back(j);
            }
        }
    }
    for (auto i : row)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (auto i : col)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            matrix[j][i] = 0;
        }
    }
    return matrix;
}

vector<vector<int>> setZeroesOptimal(vector<vector<int>> &matrix)
{
    bool firstrowzero = false;
    bool firstcolzero = false;

    for (int i = 0; i < matrix[0].size(); i++)
    {
        if (matrix[0][i] == 0)
        {
            firstrowzero = true;
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
        {
            firstcolzero = true;
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[i].size(); j++)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstrowzero)
    {
        for (int i = 0; i < matrix[0].size(); i++)
        {
            matrix[0][i] = 0;
        }
    }

    if (firstcolzero)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> matrix1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    cout << "Original Matrix 1:" << endl;
    printMatrix(matrix1);

    cout << "Better Approach Output:" << endl;
    vector<vector<int>> result1 = setZeroesBetter(matrix1);
    printMatrix(result1);

    cout << "Original Matrix 2:" << endl;
    printMatrix(matrix2);

    cout << "Optimal Approach Output:" << endl;
    vector<vector<int>> result2 = setZeroesOptimal(matrix2);
    printMatrix(result2);

    return 0;
}
