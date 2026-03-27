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
    void insertAtBeg(Node *&head, int value)
    {
        Node *newnode = new Node(value);
        newnode->next = head;
        head = newnode;
    };
    void insertAtEnd(Node *&head, int value)
    {
        if (head == NULL)
        {
            Node *newnode = new Node(value);
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(value);
    };
    void insertAtPos(Node *&head, int value, int pos)
    {
        int len = length(head);
        if (pos > len + 1 && pos <= 0)
        {
            cout << "Invalid Case";
            return;
        }
        if (pos == 1)
        {
            insertAtBeg(head, value);
        }
        else if (pos == len + 1)
        {
            insertAtEnd(head, value);
        }
        else
        {
            Node *temp = head;
            int count = 1;
            while (count < pos - 1)
            {
                count++;
                temp = temp->next;
            }
            Node *newnode = new Node(value);
            newnode->next = temp->next;
            temp->next = newnode;
        }
    };
    int length(Node *head)
    {
        int value = 0;
        if (head == NULL)
        {
            return 0;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            value++;
            temp = temp->next;
        }
        return value;
    };
    void display(Node *head)
    {
        if (head == NULL)
        {
            cout << "No Element ";
            return;
        }
        Node *temp = head;
        cout << "Printing LinkedList : ";
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    };
    void deleteFromBeg(Node *&head)
    {
        if (head == NULL)
        {
            cout << "No Element ";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    };
    void deleteFromEnd(Node *&head)
    {
        if (head == NULL)
        {
            cout << "No Element ";
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *del = temp->next;
        temp->next = NULL;
        delete del;
    };
    void deleteByValue(Node *&head, int value)
    {
        if (head == NULL)
        {
            cout << "No Element ";
            return;
        }
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL && temp->next->data != value)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Value is Not There";
            return;
        }
        Node *val = temp->next;
        temp->next = val->next;
        delete val;
    };
    void deleteAtPosition(Node *&head, int pos)
    {
        int len = length(head);
        if (pos > len && pos <= 0)
        {
            cout << "Enter a Valid Position" << endl;
            return;
        }
        if (pos == 1)
        {
            deleteFromBeg(head);
        }
        else if (pos == len)
        {
            deleteFromEnd(head);
        }
        else
        {
            int count = 1;
            Node *temp = head;
            while (count < pos - 1)
            {
                count++;
                temp = temp->next;
            }
            Node *val = temp->next;
            temp->next = val->next;
            delete val;
        }
    };

    void search(Node *head, int searchValue)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == searchValue)
            {
                cout << "Element Found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Element Not Found" << endl;
    };
};

int main()
{
    Node *head = NULL; // Start with an empty list
    Node obj(0);       // Temporary Node object to call functions

    // Insert elements
    obj.insertAtBeg(head, 10);    // List: 10
    obj.insertAtBeg(head, 5);     // List: 5 -> 10
    obj.insertAtEnd(head, 20);    // List: 5 -> 10 -> 20
    obj.insertAtPos(head, 15, 3); // List: 5 -> 10 -> 15 -> 20

    // Display the list
    obj.display(head); // Output: Printing LinkedList : 5 -> 10 -> 15 -> 20

    // Search for elements
    obj.search(head, 15); // Output: Element Found
    obj.search(head, 25); // Output: Element Not Found

    // Delete elements
    obj.deleteFromBeg(head); // List: 10 -> 15 -> 20
    obj.display(head);

    obj.deleteFromEnd(head); // List: 10 -> 15
    obj.display(head);

    obj.deleteByValue(head, 10); // List: 15
    obj.display(head);

    obj.deleteAtPosition(head, 1); // List becomes empty
    obj.display(head);

    return 0;
}
