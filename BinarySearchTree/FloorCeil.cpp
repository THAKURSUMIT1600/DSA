#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

Node *insert(Node *root, int data) {
  if (root == NULL)
    return new Node(data);

  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);

  return root;
}

int floor(Node *root, int data) {
  int floorvalue = -1;
  while (root) {

    if (root->data == data) {
      return data;
    }

    else if (root->data > data) {
      root = root->left;
    } else {
      floorvalue = root->data;
      root = root->right;
    }
  }
  return floorvalue;
}

int ceil(Node *root, int data) {
  int ceilvalue = -1;
  while (root) {
    if (root->data == data) {
      return data;
    }

    else if (root->data < data) {
      root = root->right;
    } else {
      ceilvalue = root->data;
      root = root->left;
    }
  }
  return ceilvalue;
}

void inorder(Node *root) {
  if (root == NULL)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main() {
  Node *root = NULL;

  // Insert values
  root = insert(root, 9);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 2);
  root = insert(root, 4);
  root = insert(root, 6);
  root = insert(root, 8);

  cout << "Inorder Traversal: ";
  inorder(root);

  cout << "\n";
  int data = 5;
  cout << "Floor : " << floor(root, data) << endl;
  cout << "Ceil : " << ceil(root, data) << endl;

  return 0;
}