#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int five = 0; // count of $5 bills
    int ten = 0;  // count of $10 bills

    for (int bill : bills)
    {
        if (bill == 5)
        {
            five++;
        }
        else if (bill == 10)
        {
            if (five == 0)
                return false;

            five--;
            ten++;
        }
        else // bill == 20
        {
            // Prefer giving 10 + 5
            if (ten > 0 && five > 0)
            {
                ten--;
                five--;
            }
            // Otherwise give three 5s
            else if (five >= 3)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
    vector<int> bills = {5, 5, 10, 20};

    bool result = lemonadeChange(bills);

    if (result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}