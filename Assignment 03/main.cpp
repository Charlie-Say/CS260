/*
    Design, implement, and test a Queue data structure that:
    - uses a linked-list to store the values of the queue
    - has an enqueue function that will appropriately add a value to the back of the queue as an appropriate element
    - has a dequeue function that will appropriately remove an element from the front of the queue and return its value

    Time complexity analysis for this program would be O(n). As the amount of input increases, so does the steps
    required to change the pointers to a different value. The value in this case would not matter since they are not
    used in the program, but only function as an input. With the amount of input increasing, the complexity will grow
    in linear complexity, O(n).

*/

#include <iostream>
#include <string>
using namespace std;

struct node {
    int data;
    struct node *next;
};

class linked_list {

private:
    node *head,*tail;

public:
    linked_list() {
        head = NULL;
        tail = NULL;
    }

/* Add a value to BACK of the queue */
    void enqueue(int n) {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL) {
            head = tmp;
            tail = tmp;
        }

        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    node* gethead() {
        return head;
    }

    static void display(node *head) {
        if(head == NULL) {
            cout << "NULL" << endl;
        }

        else {
            cout << head->data << endl;
            display(head->next);
        }
    }

/* Remove element from FRONT of the queue and return its value */
    int dequeue() {
        node* temp;
        temp = head;
        head = head->next;
        delete temp;
        return 0;
    }
};

/* Driver code */ 
int main() {

    int data;
    int counter = 5;
    int inputCounter = 3;
    string yesNo;
    linked_list randomList;

    while (true) {
        cout << "Add a value:  ";
        cin >> data;
        randomList.enqueue(data);
        counter--;

        if (counter == 0) {
            break;
        }
    }

    while (true) {
        cout << "Remove value from front of queue. PRESS Y: ";
        cin >> yesNo;
        if (yesNo == "y") {
            randomList.dequeue();
            linked_list::display(randomList.gethead());
            inputCounter--;

        } else {
            linked_list::display(randomList.gethead());
        }

        if (inputCounter == 0) {
            break;
        }
    }

    return 0;
}