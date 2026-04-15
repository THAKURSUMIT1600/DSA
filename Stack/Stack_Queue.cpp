#include <iostream>
#include <queue>
using namespace std;

class QueueStack
{
private:
    queue<int> q;

public:
    void push(int value)
    {
        int n = q.size();
        q.push(value);

        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int a = q.front();
        q.pop();
        return a;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return q.front();
    }

    bool isEmpty()
    {
        return q.empty();
    }
};

int main()
{
    QueueStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30
    cout << st.pop() << endl; // 30
    cout << st.top() << endl; // 20

    return 0;
}