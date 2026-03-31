#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(vector<string> &allStrings, string &current, int n);

int main()
{
    int n;
    string current = "";
    cin >> n;

    vector<string> allStrings;

    generate(allStrings, current, n);

    for (int i = 0; i < allStrings.size(); i++)
    {
        cout << allStrings[i] << endl;
    }

    return 0;
}

void generate(vector<string> &allStrings, string &current, int n)
{
    if (current.length() == n)
    {
        allStrings.push_back(current);
        return;
    }
    current += '0';
    generate(allStrings, current, n);
    current.pop_back();

    if (current.empty() || current.back() != '1')
    {
        current += '1';
        generate(allStrings, current, n);
        current.pop_back();
    }
}