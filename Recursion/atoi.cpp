#include <iostream>
#include <string>
using namespace std;

struct RecursiveAtoi
{
    int atoisolve(const string &s, int start, int currentvalue)
    {
        if (start == s.size())
        {
            return currentvalue;
        }
        int digit = s[start] - '0';
        return atoisolve(s, start + 1, currentvalue * 10 + digit);
    }
    int atoi(const string &s)
    {
        int sign = 1;
        int start = 0;

        if (s[0] == '-')
        {
            sign = -1;
            start = 1;
        }
        else if (s[0] == '+')
        {
            start = 1;
        }

        // Skip leading zeros AFTER sign
        while (start < s.size() && s[start] == '0')
        {
            start++;
        }

        return sign * atoisolve(s, start, 0);
    }
};

int main()
{
    string s;
    cin >> s;

    RecursiveAtoi obj;
    int length = s.size();
    int result = obj.atoi(s);

    cout << result << endl;

    return 0;
}