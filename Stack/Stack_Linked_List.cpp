#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *head;

public:
    // Constructor
    Stack()
    {
        head = nullptr;
    }

    // Push operation
    void push(int value)
    {

        Node *newnode = new Node;
        newnode->data = value;
        newnode->next = head;
        head = newnode;
    }

    // Pop operation
    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Return top element
    int top()
    {
        return (head == NULL) ? -1 : head->data;
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return (head == NULL) ? true : false;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.pop();

    cout << "Top element: " << s.top() << endl;

    if (s.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}