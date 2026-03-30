#include <iostream>
#include <vector>
using namespace std;

struct CombinationSumIII
{
    void generate(int start,
                  int k,
                  int target,
                  vector<int> &current,
                  vector<vector<int>> &result)
    {
        if (target == 0 && current.size() == k)
        {
            result.push_back(current);
            return;
        }
        if (target < 0 || current.size() >= k)
            return;
        for (int i = start; i <= 9; i++)
        {
            if (i > target)
            {
                break;
            }
            current.push_back(i);
            generate(i + 1, k, target - i, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> current;
        generate(1, k, n, current, result);
        return result;
    }
};

int main()
{
    CombinationSumIII obj;

    int k = 3;
    int n = 9;

    vector<vector<int>> answer = obj.combinationSum3(k, n);

    for (auto &vec : answer)
    {
        cout << "[ ";
        for (int num : vec)
            cout << num << " ";
        cout << "]\n";
    }

    return 0;
}