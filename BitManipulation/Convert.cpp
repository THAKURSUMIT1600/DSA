#include <iostream>
using namespace std;

class Solution
{
public:
    int countSetBits(int num)
    {
        int count = 0;

        while (num != 0)
        {
            num = num & (num - 1);
            count++;
        }

        return count;
    }

    int convert(int start, int goal)
    {
        int a = start ^ goal;
        return countSetBits(a);
    }
};

int main()
{
    int start, goal;

    cout << "Enter start ";
    cin >> start;
    cout << "Enter goal ";
    cin >> goal;

    Solution obj;
    int result = obj.convert(start, goal);

    cout << "Minimum bit flips required: " << result << endl;

    return 0;
}