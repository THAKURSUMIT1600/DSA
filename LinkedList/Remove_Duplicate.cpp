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

struct DoublyLinkedList
{

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
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

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

    Node *removeDuplicates(Node *head)
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data == temp->next->data)
            {
                Node *duplicate = temp->next;

                temp->next = duplicate->next;

                if (duplicate->next != NULL)
                {
                    duplicate->next->prev = temp;
                }

                delete duplicate;
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

    dll.insertAtEnd(head, 1);
    dll.insertAtEnd(head, 1);
    dll.insertAtEnd(head, 1);
    dll.insertAtEnd(head, 2);
    dll.insertAtEnd(head, 2);
    dll.insertAtEnd(head, 3);
    dll.insertAtEnd(head, 3);
    dll.insertAtEnd(head, 3);
    dll.insertAtEnd(head, 4);
    dll.insertAtEnd(head, 4);

    cout << "Original List: ";
    dll.printList(head);

    head = dll.removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    dll.printList(head);

    return 0;
}