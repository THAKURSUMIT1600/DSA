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
int length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *getIntersectionNode(Node *headA, Node *headB)
{
    int count = 0;
    Node *intersection = NULL;
    int lena = length(headA);
    int lenb = length(headB);
    int abss = abs(lena - lenb);
    if (lena > lenb)
    {
        while (abss)
        {
            headA = headA->next;
            abss--;
        }
    }
    else
    {
        while (abss)
        {
            headB = headB->next;
            abss--;
        }
    }
    while (headA && headB)
    {
        if (headA == headB)
        {
            if (intersection == NULL)
            {
                intersection = headA;
            }
            count++;
        }
        else
        {
            count = 0;
            intersection = NULL;
        }
        headA = headA->next;
        headB = headB->next;
    }
    if (count > 0)
    {
        return intersection;
    }
    return NULL;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *common = new Node(8);
    common->next = new Node(10);

    Node *headA = new Node(3);
    headA->next = new Node(6);
    headA->next->next = new Node(9);
    headA->next->next->next = common;

    Node *headB = new Node(4);
    headB->next = common;

    Node *intersection = getIntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->data;
    else
        cout << "No intersection";

    return 0;
}