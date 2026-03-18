#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int assignCookies(vector<int> &student, vector<int> &cookie)
{
    sort(student.begin(), student.end());
    sort(cookie.begin(), cookie.end());
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < student.size() && j < cookie.size())
    {
        if (cookie[j] >= student[i])
        {
            count++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return count;
}

int main()
{
    vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 1};

    int result = assignCookies(student, cookie);

    cout << "Maximum students satisfied: " << result << endl;

    return 0;
}