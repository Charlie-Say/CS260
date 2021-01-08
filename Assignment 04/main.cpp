/*
    Create an array-based list and then a linked-list that allows:
    - an add function that takes a value and inserts it into a given position into the list
      (example: myList.add(someValue, somePosition) )
    - a remove function that takes a position and removes the value stored at that position of the list and returns it
      (example: myList.remove(somePosition) )
    - a get function that takes a position and returns that value without removing it


    Time complexity analysis for this program would be O(n). This program compares the input to the position starting from the head
    of the node. The value in this case does not matter, but the container size (linked list) would change how long the algorithm
    would take to complete the process. The larger the container, the more comparisons that could possibly take place to find the
    correct position of the input.

*/

#include <bits/stdc++.h>
using namespace std;

// A linked list Node
struct Node {
    int data;
    struct Node* next;
};

// Size of linked list
int size = 0;

// function to create and return a Node
Node* getNode(int data)
{
    // allocating space
    Node* newNode = new Node();

    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a Node at required position
void insertPos(Node** current, int pos, int data)
{
    // This condition to check whether the
    // position given is valid or not.
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else {

        // Keep looping until the pos is zero
        while (pos--) {

            if (pos == 0) {

                // adding Node at required position
                Node* temp = getNode(data);

                // Making the new Node to point to
                // the old Node at the same position
                temp->next = *current;

                // Changing the pointer of the Node previous
                // to the old Node to point to the new Node
                *current = temp;
            }
            else
              // Assign double pointer variable to point to the
              // pointer pointing to the address of next Node
              current = &(*current)->next;
        }
        size++;
    }
}

void deleteNode(struct Node **head_ref, int position)
{ 
   // If linked list is empty
   if (*head_ref == NULL)
      return;

   // Store head node
   struct Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;

    // If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL)
         return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node *next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next);  // Free memory

    temp->next = next;  // Unlink the deleted node from list
}

// This function prints contents
// of the linked list
void printList(struct Node* head)
{
    while (head != NULL) {
        cout << " " << head->data;
        head = head->next;
    }
    cout << endl;
}

// Driver Code
int main()
{
    // Creating the list 3->5->8->10
    Node* head = NULL;
    head = getNode(3);
    head->next = getNode(5);
    head->next->next = getNode(8);
    head->next->next->next = getNode(10);

    size = 4;

    cout << "Linked list before insertion: ";
    printList(head);

    int data = 12, pos = 3;
    insertPos(&head, pos, data);
    cout << "Linked list after insertion of 12 at position 3: ";
    printList(head); 

    // front of the linked list
    data = 1, pos = 1;
    insertPos(&head, pos, data);
    cout << "Linked list after insertion of 1 at position 1: ";
    printList(head); 

    // insertion at end of the linked list
    data = 15, pos = 7;
    insertPos(&head, pos, data);
    cout << "Linked list after insertion of 15 at position 7: ";
    printList(head);

     // delete node at end of the linked list
    pos = 5;
    deleteNode(&head, pos); 
    cout << "Linked list after deletion of 10 at position 6: ";
    printList(head);

    return 0;
}