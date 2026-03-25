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
Node *removeNthFromEnd(Node *head, int n)
{
    if (head == NULL)
        return NULL;

    int length = 0;
    Node *temp = head;

    // Count length
    while (temp)
    {
        length++;
        temp = temp->next;
    }

    // If head needs to be removed
    if (n == length)
    {
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
        return head;
    }

    // Move to node before the one to delete
    temp = head;
    for (int i = 1; i < length - n; i++)
    {
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;

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

    cout << "Original List: ";
    printList(head);

    int n;
    cout << "Enter value of n: ";
    cin >> n;

    head = removeNthFromEnd(head, n);

    cout << "Modified List: ";
    printList(head);

    return 0;
}