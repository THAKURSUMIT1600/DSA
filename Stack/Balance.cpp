#include <iostream>
#include <stack>
using namespace std;

bool checkBalance(string str)
{
    stack<char> st;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else
        {
            if (str[i] == ')' || str[i] == '}' || str[i] == ']')
            {
                if (st.empty())
                {
                    return false;
                }
                if (st.top() == '(' && str[i] == ')' || st.top() == '{' && str[i] == '}' || st.top() == '[' && str[i] == ']')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return (st.empty()) ? true : false;
}

int main()
{
    string str;
    cin >> str;

    if (checkBalance(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}