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

Node *deleteMiddle(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        head = NULL;
        return head;
    }
    Node *midless = NULL;
    Node *mid = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        midless = mid;
        mid = mid->next;
        fast = fast->next->next;
    }
    midless->next = mid->next;
    mid->next = NULL;
    delete mid;
    return head;
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
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }

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

    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        head = insert(head, value);
    }

    cout << "Original List: ";
    printList(head);

    head = deleteMiddle(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}