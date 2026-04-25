#include <iostream>
#include <utility>

struct Node
{
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

std::pair<int, int> inorderSuccessorPredecessor(Node *root, int key)
{
    int suc = -1;
    int pred = -1;

    Node *curr = root;

    while (curr)
    {
        if (curr->val < key)
        {
            pred = curr->val;
            curr = curr->right;
        }
        else if (curr->val > key)
        {
            suc = curr->val;
            curr = curr->left;
        }
        else
        {

            // find largest in left

            if (curr->left)
            {
                Node *temp = curr->left;
                while (temp->right)
                {
                    temp = temp->right;
                }
                pred = temp->val;
            }

            // find smallest in right
            if (curr->right)
            {
                Node *temp = curr->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                suc = temp->val;
            }

            break;
        }
    }

    return {suc, pred};
}

int main()
{
    /*
            20
           /  \
          9    25
         / \
        5   12
           /  \
          11  14
    */

    Node *root = new Node(20);

    root->left = new Node(9);
    root->right = new Node(25);

    root->left->left = new Node(5);
    root->left->right = new Node(12);

    root->left->right->left = new Node(11);
    root->left->right->right = new Node(14);

    int key = 20;

    auto res = inorderSuccessorPredecessor(root, key);

    if (res.first)
        std::cout << "Successor: " << res.first << "\n";
    else
        std::cout << "Successor: None\n";

    if (res.second)
        std::cout << "Predecessor: " << res.second << "\n";
    else
        std::cout << "Predecessor: None\n";

    return 0;
}