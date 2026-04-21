#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class Solution
{
public:
    Node *deleteDLL(Node *head, int key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                if (temp->prev == NULL)
                {
                    Node *t = temp->next;

                    if (t != NULL)
                        t->prev = NULL;

                    head = t;
                    delete temp;
                    temp = t;
                }
                else if (temp->next == NULL)
                {
                    Node *t = temp->prev;
                    t->next = NULL;
                    delete temp;
                    break;
                }
                else
                {
                    Node *first = temp->prev;
                    Node *second = temp->next;
                    first->next = second;
                    second->prev = first;
                    delete temp;
                    temp = second;
                }
            }
            else
            {
                temp = temp->next;
            }
        }

        return head;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    // DLL: 2 <-> 1 <-> 3 <-> 2 <-> 4 <-> 5 <-> 2
    // Cases:
    // - Head deletion (2 at start)
    // - Middle deletion (2 in between)
    // - End deletion (2 at last)

    Node *head = new Node(2); // head case
    Node *n2 = new Node(1);
    Node *n3 = new Node(3);
    Node *n4 = new Node(2); // middle case
    Node *n5 = new Node(4);
    Node *n6 = new Node(5);
    Node *n7 = new Node(2); // end case

    // Linking
    head->next = n2;

    n2->prev = head;
    n2->next = n3;

    n3->prev = n2;
    n3->next = n4;

    n4->prev = n3;
    n4->next = n5;

    n5->prev = n4;
    n5->next = n6;

    n6->prev = n5;
    n6->next = n7;

    n7->prev = n6;

    cout << "Original DLL: ";
    printList(head);

    Solution obj;
    head = obj.deleteDLL(head, 2);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}