#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
    void insertAtBeg(Node *&head, int value)
    {
        Node *temp = new Node(value);
        if (head != NULL)
        {
            temp->next = head;
            head->prev = temp;
        }
        head = temp;
    }
    void insertAtEnd(Node *&head, int value)
    {
        Node *temp = new Node(value);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        Node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
        temp->prev = t;
    }

    void deleteFromBeg(Node *&head)
    {
        if (head == NULL)
            return;
        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }
    void deleteFromEnd(Node *&head)
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    void deleteByValue(Node *&head, int value)
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp != NULL && temp->data != value)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return;
        }
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = head->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
    void traverseFront(Node *&head)
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        cout << "Element : ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void traverseBackend(Node *&head)
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "Element : ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }
};
int main()
{
    Node *head = NULL;
    Node list(0); // dummy object to access member functions

    // Insert at beginning
    list.insertAtBeg(head, 10);
    list.insertAtBeg(head, 20);
    list.insertAtBeg(head, 30);

    cout << "After inserting at beginning:\n";
    list.traverseFront(head);
    cout << endl;

    // Insert at end
    list.insertAtEnd(head, 40);
    list.insertAtEnd(head, 50);

    cout << "After inserting at end:\n";
    list.traverseFront(head);
    cout << endl;

    // Traverse backward
    cout << "Traverse backward:\n";
    list.traverseBackend(head);
    cout << endl;

    // Delete from beginning
    list.deleteFromBeg(head);
    cout << "After deleting from beginning:\n";
    list.traverseFront(head);
    cout << endl;

    // Delete from end
    list.deleteFromEnd(head);
    cout << "After deleting from end:\n";
    list.traverseFront(head);
    cout << endl;

    // Delete by value
    list.deleteByValue(head, 20);
    cout << "After deleting value 20:\n";
    list.traverseFront(head);
    cout << endl;

    return 0;
}