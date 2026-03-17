#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Linked List class
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insert at end
    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Display list
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Find middle elements
    Node *findMiddle()
    {
        if (head == nullptr)
            return nullptr;
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main()
{
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Linked List: ";
    list.display();

    Node *middle = list.findMiddle();

    if (middle != nullptr)
        cout << "Middle Element: " << middle->data << endl;

    return 0;
}