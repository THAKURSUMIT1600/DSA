#include <iostream>
#include <stack>
using namespace std;

class QueueStack
{
private:
    stack<int> st1;
    stack<int> st2;

public:
    void push(int value)
    {
        st1.push(value);
        cout << value << " pushed into queue\n";
    }

    int pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }

        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int popvalue = st2.top();
        st2.pop();
        return popvalue;
    }

    int peek()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }

        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    bool isEmpty()
    {
        return st1.empty() && st2.empty();
    }
};

int main()
{
    QueueStack q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;

    cout << "Popped element: " << q.pop() << endl;
    cout << "Popped element: " << q.pop() << endl;

    cout << "Front element after pops: " << q.peek() << endl;

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.pop(); // remove last element

    cout << "Is queue empty after removing all elements? "
         << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}