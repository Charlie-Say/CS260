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

    // Add a value to BACK of the queue
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

// Remove element from FRONT of the queue and return its value
    int dequeue()
    {
        node* temp;
        temp = head;
        head = head->next;
        delete temp;
        return 0;
    }
};


// Driver code 
int main() 
{
    int data;
    int counter = 5;
    int inputCounter = 3;
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

    while (true)
    {
        cout << "Remove value from front of queue. PRESS Y: ";
        cin >> yesNo;
        if (yesNo == "y")
        {
            randomList.dequeue();
            linked_list::display(randomList.gethead());
            inputCounter--;
        } else {
            linked_list::display(randomList.gethead());
        }

        if (inputCounter == 0)
        {
            break;
        }
    }

    return 0;
}