#include <iostream>
#include <string>
#include <list>
using namespace std;

void printList(list<int> mylist) 
{ 
  
    // Get the iterator 
    list<int>::iterator it; 
  
    // printing all the elements of the list 
    for (it = mylist.begin(); it != mylist.end(); ++it) 
        cout << ' ' << *it; 
    cout << '\n'; 
}


int main ()
{
    cout << "Hello Woreeeld!" << endl;

    string rem_add;
    string remove = "remove";
    string add = "add";

    int amountMarbles;
    //create array (bag)
    int total_ele;
    list<int> bag;
    list<int>::iterator it;

    for (int i=0; i<5; i++) bag.push_back(0);

    //check amount of marbles in bag
    cout << "There are currently " << (int) bag.size() << "marbles in the bag" << endl;

    //if statement add or remove marbles
    cout << "Would you like to 'add' or 'remove' marbles? ";
    cin >> rem_add;

    if (rem_add != add || rem_add != remove)
    {
        cout << "Not valid command!" << endl;
    }

    cout << "How many marbles? ";
    cin >> amountMarbles;

    if (amountMarbles > 50)
    {
        cout << "Too many marbles" << endl;
        return 0;
    }

    if (rem_add == add)
    {
        for (int i=0; i < amountMarbles; i++)
        {
            bag.push_back(0);
        }
    }
    else if (rem_add == remove)
    {
        for (int i=0; i < amountMarbles; i++)
        {
            bag.pop_back();
        }
    }

    cout << "There are now " << (int) bag.size() << "in the bag." << endl;

    return 0;
}