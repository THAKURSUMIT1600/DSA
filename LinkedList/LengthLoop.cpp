#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Function to find length of loop
int findLoopLength(Node *head)
{
    // first detect loop
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            Node *t = slow->next;
            int count = 1;
            while (t != slow)
            {
                count++;
                t = t->next;
            }
            return count;
        }
    }
    return 0;
}

int main()
{
    // Creating nodes manually
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a loop (for testing)
    fifth->next = third;

    int length = findLoopLength(head);

    if (length > 0)
        cout << "Length of loop: " << length << endl;
    else
        cout << "No loop detected" << endl;

    return 0;
}