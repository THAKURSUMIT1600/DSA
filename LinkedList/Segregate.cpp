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

Node *segregate(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *evenStart = NULL, *evenEnd = NULL;
    Node *oddStart = NULL, *oddEnd = NULL;

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            if (evenStart == NULL)
            {
                evenStart = evenEnd = curr;
            }
            else
            {
                evenEnd->next = curr;
                evenEnd = curr;
            }
        }
        else
        {
            if (oddStart == NULL)
            {
                oddStart = oddEnd = curr;
            }
            else
            {
                oddEnd->next = curr;
                oddEnd = curr;
            }
        }

        curr = curr->next;
    }

    if (evenStart == NULL)
        return oddStart;

    evenEnd->next = oddStart;

    if (oddEnd != NULL)
        oddEnd->next = NULL;

    return evenStart;
}

Node *insert(Node *head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
        return newNode;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;

    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);

    cout << "Original List: ";
    printList(head);

    head = segregate(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}