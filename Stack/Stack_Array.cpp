#include <iostream>
using namespace std;

class ArrayStack
{
private:
    int *arr;
    int capacity;
    int topIndex;

public:
    ArrayStack(int value)
    {
        capacity = value;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int value)
    {
        if (topIndex == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = value;
    }

    int pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1; // Sentinel value
        }
        return arr[topIndex--];
    }

    int top()
    {
        if (topIndex == -1)
        {
            cout << "Stack Empty" << endl;
            return -1; // Sentinel value
        }
        return arr[topIndex];
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    bool isFull()
    {
        return topIndex == capacity - 1;
    }

    ~ArrayStack()
    {
        delete[] arr;
    }
};

int main()
{
    ArrayStack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;

    cout << "Popped element: " << stack.pop() << endl;

    if (stack.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}