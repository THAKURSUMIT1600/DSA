#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *addOne(Node *head)
{
    Node *rev = reverse(head);
    Node *prev = rev;
    bool one = true;
    Node *lastval = head;
    while (prev != NULL)
    {
        int data = 0;
        if (one)
        {
            data += 1;
        }
        data += prev->data;
        if (data > 9)
        {
            one = true;
            prev->data = 0;
        }
        else
        {
            prev->data = data;
            one = false;
        }
        lastval = prev;
        prev = prev->next;
    }
    if (one)
    {
        Node *newnode = new Node(1);
        lastval->next = newnode;
    }
    rev = reverse(rev);
    return rev;
}

void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    insert(head, 9);
    insert(head, 9);
    insert(head, 9);

    head = addOne(head);

    printList(head);

    return 0;
}
// commit-marker: 2026-03-03
