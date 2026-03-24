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
            temp = temp->next;

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

    vector<pair<int, int>> findPairsWithSum(Node *head, int target)
    {
        vector<pair<int, int>> st;
        Node *start = head;
        Node *end = head;
        while (end->next != NULL)
        {
            end = end->next;
        }
        while (start != NULL && end != NULL &&
               start != end && start->prev != end)
        {
            if ((start->data + end->data) == target)
            {
                st.push_back({start->data, end->data});
                end = end->prev;
                start = start->next;
            }
            else if ((start->data + end->data) > target)
            {
                end = end->prev;
            }
            else
            {
                start = start->next;
            }
        }
        return st;
    }
};

int main()
{
    Node *head = NULL;
    DoublyLinkedList dll;

    dll.insertAtEnd(head, 1);
    dll.insertAtEnd(head, 2);
    dll.insertAtEnd(head, 4);
    dll.insertAtEnd(head, 5);
    dll.insertAtEnd(head, 6);
    dll.insertAtEnd(head, 8);
    dll.insertAtEnd(head, 9);

    cout << "Doubly Linked List: ";
    dll.printList(head);

    int target = 7;

    cout << "Pairs with sum " << target << endl;
    vector<pair<int, int>> st = dll.findPairsWithSum(head, target);
    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i].first << " " << st[i].second << endl;
    }

    return 0;
}