
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, char> st;
        unordered_map<char, char> ts;

        for (int i = 0; i < s.size(); i++)
        {

            if (st.count(s[i]) && st[s[i]] != t[i])
                return false;
            if (ts.count(t[i]) && ts[t[i]] != s[i])
                return false;

            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
        return true;
    }
};

int main()
{
    Solution obj;

    string s = "egg";
    string t = "ade";

    bool result = obj.isIsomorphic(s, t);

    if (result)
        cout << "True";
    else
        cout << "False";

    return 0;
}
