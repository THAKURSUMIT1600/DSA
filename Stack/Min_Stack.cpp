#include <iostream>
#include <stack>
using namespace std;

struct MinStack
{
    stack<long long> st;
    long long minVal;

    MinStack()
    {
        while (!st.empty())
            st.pop();
        minVal = 0;
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else if (val < minVal)
        {
            // encode new minimum
            st.push(2LL * val - minVal);
            minVal = val;
        }
        else
        {
            st.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long topVal = st.top();
        st.pop();
        if (topVal < minVal)
        {
            // encoded value → recover previous min
            minVal = 2 * minVal - topVal;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;
        long long topVal = st.top();
        return (topVal >= minVal) ? topVal : minVal; // decode if encoded
    }

    int getMin()
    {
        if (st.empty())
            return -1;
        return minVal;
    }

    bool empty()
    {
        return st.empty();
    }
};

int main()
{
    MinStack s;

    s.push(3);
    s.push(5);
    cout << "Current Min: " << s.getMin() << endl; // 3

    s.push(2);
    s.push(1);
    cout << "Current Min: " << s.getMin() << endl; // 1

    s.pop();
    cout << "Current Min after pop: " << s.getMin() << endl; // 2
    cout << "Current Top: " << s.top() << endl;              // 2

    s.pop();
    cout << "Current Top after pop: " << s.top() << endl; // 5
    cout << "Current Min: " << s.getMin() << endl;        // 3

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}