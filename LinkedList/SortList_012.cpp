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

Node *sortList(Node *head)
{
    Node *zero = new Node(-1);
    Node *one = new Node(-1);
    Node *two = new Node(-1);
    Node *zerohead = zero;
    Node *onehead = one;
    Node *twohead = two;
    Node *temp = head;

    while (temp)
    {
        Node *nextNode = temp->next;
        temp->next = NULL;
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
            zero->next = NULL;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
            one->next = NULL;
        }
        else
        {
            two->next = temp;
            two = two->next;
            two->next = NULL;
        }

        temp = nextNode;
    }
    zerohead = zerohead->next;
    onehead = onehead->next;
    twohead = twohead->next;
    zero->next = onehead;
    one->next = twohead;

    return zerohead;
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
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    insert(head, 1);
    insert(head, 0);
    insert(head, 2);
    insert(head, 1);
    insert(head, 0);
    insert(head, 0);

    head = sortList(head);

    printList(head);

    return 0;
}