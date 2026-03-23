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

Node *findmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node *merge(Node *left, Node *right)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (left && right)
    {
        if (left->data <= right->data)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
        temp->next = NULL;
    }
    if (left)
    {
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }

    if (right)
    {
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }
    return dummy->next;
}
Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // find mid
    Node *mid = findmid(head);
    Node *next = mid->next;
    mid->next = NULL;
    Node *left = sortList(head);
    Node *right = sortList(next);

    return merge(left, right);
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

    head = insert(head, 4);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 3);
    head = insert(head, 5);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}