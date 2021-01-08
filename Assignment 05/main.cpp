/*
    Create an array-based list or a linked-list (and then attempt the other) that:
    - automatically inserts values in the correct position based on some order of sorting (perhaps ascending integers or lexicographical sorting of words)
    - efficiently searches for elements (likely binary search for the array list, but what about the linked-list?)

*/

#include <iostream>
#include <string>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

/* Add a value to BACK of the queue */
    void enqueue(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    node* gethead()
    {
        return head;
    }

    static void display(node *head)
    {
        if(head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
    }
    // help source: https://www.javatpoint.com/program-to-sort-the-elements-of-the-singly-linked-list
    // sortList() will sort nodes of the list in ascending order
    static void sortList(node *head) {
        //Node current will point to head
        struct node *current = head, *index = NULL;
        int temp;

        if(head == NULL) {
            return;
        }
        else {
            while(current != NULL) {
                //Node index will point to node next to current
                index = current->next;

                while(index != NULL) {
                    //If current node's data is greater than index's node data, swap the data between them
                    if(current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }

};

/* Driver code */
int main()
{
    int data;
    int counter = 5;
    string yesNo;
    linked_list randomList;

    while (true)
    {
        cout << "Add a value:  ";
        cin >> data;
        randomList.enqueue(data);
        counter--;

        if (counter == 0)
        {
            break;
        }
    }

    cout << "Your current list is:" << endl;
    linked_list::display(randomList.gethead());
    cout << " " << endl;

    cout << "Your sorted list in ascending order is:" << endl;
    linked_list::sortList(randomList.gethead());
    linked_list::display(randomList.gethead());

    return 0;
}