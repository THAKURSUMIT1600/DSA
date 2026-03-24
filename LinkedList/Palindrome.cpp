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

Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if linked list is palindrome
bool isPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    Node *p = head;
    slow = slow->next;
    while (slow != NULL)
    {
        if (p->data != slow->data)
        {
            return false;
        }
        p = p->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    // Creating nodes manually
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(2);
    Node *fifth = new Node(4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    if (isPalindrome(head))
        cout << "Linked List is Palindrome" << endl;
    else
        cout << "Linked List is NOT Palindrome" << endl;

    return 0;
}