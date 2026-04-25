#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}
Node *findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int olddata)
{
    if (root == NULL)
        return NULL;

    if (root->data > olddata)
    {
        root->left = deleteNode(root->left, olddata);
    }
    else if (root->data < olddata)
    {
        root->right = deleteNode(root->right, olddata);
    }
    else
    {

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node *t = root->right;
            delete root;
            return t;
        }
        else if (root->right = NULL)
        {
            Node *t = root->left;
            delete root;
            return t;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
}

Node *update(Node *root, int oldData, int newData)
{
    root = deleteNode(root, oldData);
    root = insert(root, newData);
    return root;
}

int main()
{

    return 0;
}