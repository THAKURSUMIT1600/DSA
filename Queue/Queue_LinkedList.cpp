#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

class LinkedListQueue
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    LinkedListQueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Adds element x to the end of the queue
    void push(int x)
    {
        if (rear == NULL)
        {
            Node *newnode = new Node;
            newnode->data = x;
            newnode->next = NULL;

            front = newnode;
            rear = newnode;
        }
        else
        {
            Node *newnode = new Node;
            newnode->data = x;
            newnode->next = NULL;

            rear->next = newnode;
            rear = newnode;
        }
    }

    // Removes and returns the front element
    int pop()
    {
        if (front == NULL)
        {
            return -1; // Queue Underflow
        }

        Node *temp = front;
        int value = temp->data;

        front = front->next;

        // If queue becomes empty
        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp; // Free memory

        return value;
    }

    // Returns front element without removing it
    int peek()
    {
        return (front) ? front->data : -1;
    }

    // Returns true if queue is empty
    bool isEmpty()
    {
        return (front == NULL);
    }
};

int main()
{
    LinkedListQueue q;

    q.push(10);
    q.push(20);
    q.pop();

    cout << "Front element: " << q.peek() << endl;

    if (q.isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";

    return 0;
}