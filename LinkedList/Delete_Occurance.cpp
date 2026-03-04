#include <iostream>
using namespace std;

// Node definition
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

struct DoublyLinkedList
{
    // Insert at end
    void insertAtEnd(Node *&head, int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Print list
    void printList(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Delete all occurrences of given key (EMPTY FUNCTION)
    Node *deleteAllOccurrences(Node *head, int key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                Node *d = temp;
                Node *nextNode = temp->next;
                if (d->prev == NULL)
                {
                    head = d->next;

                    if (head != NULL)
                        head->prev = NULL;
                }
                else
                {
                    Node *k = d->prev;
                    k->next = d->next;
                    if (d->next)
                    {
                        d->next->prev = k;
                    }
                }
                temp = nextNode;
                delete d;
            }
            else
            {

                temp = temp->next;
            }
        }
        return head;
    }
};

int main()
{
    Node *head = NULL;
    DoublyLinkedList dll;

    // Example list: 2 2 10 8 4 2 5 2
    dll.insertAtEnd(head, 2);
    dll.insertAtEnd(head, 2);
    dll.insertAtEnd(head, 10);
    dll.insertAtEnd(head, 8);
    dll.insertAtEnd(head, 4);
    dll.insertAtEnd(head, 2);
    dll.insertAtEnd(head, 5);
    dll.insertAtEnd(head, 2);

    cout << "Original List: ";
    dll.printList(head);

    int key = 2;

    head = dll.deleteAllOccurrences(head, key);

    cout << "After Deleting " << key << ": ";
    dll.printList(head);

    return 0;
}
// commit-marker: 2026-03-04
