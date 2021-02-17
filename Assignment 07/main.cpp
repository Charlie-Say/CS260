/*

Begin
   Initialize the table size (tableSize) to some integer value.
   Create a structure hashTableEntry to declare key variable and value variable.
   Create a class hashMapTable:
   Create a hashFunc() function which return a key.
   Create a function Insert() to insert element at a key.
   Create a function SearchKey() to search element at a key.
   (optional) Create a function Remove() to remove element at a key.
   In main, perform switch operation and enter input as per choice.
    - To insert key and values, call insertElement().
    - To search element, call searchElement().
    - To remove element, call deleteElement().
    - Display hashMap
End.

Then create a smarter hashtable (double hashing or chaining)

Think of solving collision*****
    - Seperate Chaining (Open Hashing)
    - Linear Probing (Open Addressing/Closed Hashing)
    - Quadratic Probing
    - Double Hashing

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include<list>
using namespace std;



class hashclass {

    int bucket;     // Number of buckets/size of index for storing elements
    list<int>*hashtable;        // Container 

    public:
    hashclass(int a) {       // Constructor
        bucket = a;
        hashtable = new list<int> [bucket];
    }

    void insertElement(int key) {                  // Function used to insert elements to the hashtable
        int indexkey = hashFunction(key);           // Get the hash index of key
        hashtable[indexkey].push_back(key);
    }
    void deleteElement(int key) {          // Function used to delete elements from the hashtable
        int indexkey = hashFunction(key);
        list<int>::iterator i = hashtable[indexkey].begin();

        for ( ; i != hashtable[indexkey].end(); i++) {
            if (*i == key) {
                break;
            }
        }

        if (i != hashtable[indexkey].end()) {
            hashtable[indexkey].erase(i);
        }
    }
    int hashFunction(int a) {     // Function used to map values to key
        return (a % bucket);
    }

    void dispalyTable() {           // Display hashtable values
        for (int i = 0; i < bucket; i++) {
            cout << i;
            list<int>::iterator j = hashtable[i].begin();

        for ( ; j != hashtable[i].end(); j++) {
                cout << "---->" << *j;
            }

            cout << endl;
        }
    }
    void searchElement(int key) {        // Used to search element
        int a = 0;         // Will be 1 if element exist otherwise 0
        int indexkey = hashFunction(key);
        list<int>::iterator i = hashtable[indexkey].begin();

        for ( ; i != hashtable[indexkey].end(); i++) {
            if (*i == key) {
                a=1;
                break;
            }
        }

            if (a == 1) {
                cout << "The element is present in the hashtable." << endl;
                cout << endl;
            }
            else {
                cout << "The element is not present" << endl;
                cout << endl;
            }

    }
    ~hashclass(){       // Destructor to clear memory
        delete[]hashtable;
    }


};

int main() {

    int bucketn, userChoice, element;
    cout << "Enter the no of buckets: ";
    cin >> bucketn;
    hashclass hashelement(bucketn);

    do {
        cout << "1.insert element to the hashtable" << endl;
        cout << "2.search element from the hashtable" << endl;
        cout << "3.delete element from the hashtable" << endl;
        cout << "4.display elements of the hashtable" << endl;
        cout << "5.exit" << endl;
        cout << "Enter your choice: ";

        if (cin.fail()){
            break;
        }
        else {
            cin >> userChoice;
        }


        switch(userChoice) {
            case 1: cout << "enter the element: ";
            cin >> element;

            hashelement.insertElement(element);
            break;

            case 2: cout << "Enter the element you want to search: ";
            cin >> element;

            hashelement.searchElement(element);
            break;

            case 3: cout << "Enter the element to be deleted: ";
            cin >> element;

            hashelement.deleteElement(element);
            break;

            case 4: hashelement.dispalyTable();
            break;

            case 5: return 0;
            default:cout << "Enter a valid value" << endl;
        }
    } while (true);

    return 0;
}