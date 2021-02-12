/*

Assignment 6 (Binary search tree):
1. Create some tests (at least one per function) that you want your Binary Search Tree (BST) to pass before you start coding.
2. Implement a binary search tree that includes:
    - nodes to store values,
    - an add function that adds a new value in the appropriate location based on our ordering rules,
        (I likely used less than or equal to going to the left and greater than values going to the right)
    - a remove function that finds and removes a value and then picks an appropriate replacement node
        (successor is a term often used for this)
    - we have at least one tree traversal function
        Bonus if you implement the three common traversals (pre-order, post-order, in-order)
        More Bonus if you also include a breadth-first traversal (sometimes called a level-order search)
3. Analyze and compare the complexity of insert and search as compared to a binary tree without any order in its nodes.


Source: https://www.programiz.com/dsa/binary-search-tree

*/

#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;                                                       //create root node
  temp->left = temp->right = NULL;                                        //create left and right nodes to be null for BST
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {                       //checks if root is null before traversing the BST in order
    inorder(root->left);
    cout << root->key << " -> ";            //prints the root node pointing to the key
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  if (key < node->key)                                    //if key is less than the nodes key, traverse left & insert new key if subtree is null
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);               //if key is greater than the nodes key, traverse right & insert new key if subtree is null

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

/*
Deleting a node
case 1 - if the node to be deleted is a leaf node: just delete it
case 2 - if the node has a child node: replace the node with the child node and remove the original child node
case 3 - if node has 2 child nodes: get the inorder successor of that node, replace node with the inorder successor,
          remove the inorder succesor from its original position
*/
struct node *deleteNode(struct node *root, int key) {                 
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)                                          //recursively find the node to be deleted
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  // Create BST
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Inorder traversal: ";
  inorder(root);

  // Testing delete function
  cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);
  cout << "Inorder traversal: ";
  inorder(root);
}