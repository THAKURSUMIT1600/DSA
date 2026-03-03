
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
Node *addTwoNumbers(Node *head1, Node *head2)
{
    int carry = 0;
    Node *heada = reverse(head1);
    Node *headb = reverse(head2);
    Node *result = new Node(-1);
    Node *resulthead = result;
    while (heada || headb)
    {
        int data = carry;

        if (heada || headb)
        {
            if (heada)
            {
                data += heada->data;
                heada = heada->next;
            }
            if (headb)
            {
                data += headb->data;
                headb = headb->next;
            }
            carry = data / 10;
            result->next = new Node(data % 10);
            result = result->next;
        }
    }
    if (carry > 0)
    {
        result->next = new Node(carry);
    }
    return resulthead->next;
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
    Node *head1 = NULL;
    Node *head2 = NULL;

    insert(head1, 9);
    insert(head1, 9);
    insert(head1, 9);
    insert(head1, 9);
    insert(head1, 9);
    insert(head1, 9);
    insert(head1, 9);

    insert(head2, 9);
    insert(head2, 9);
    insert(head2, 9);
    insert(head2, 9);

    Node *result = addTwoNumbers(head1, head2);

    printList(result);

    return 0;
}

// commit-marker: 2026-03-03
