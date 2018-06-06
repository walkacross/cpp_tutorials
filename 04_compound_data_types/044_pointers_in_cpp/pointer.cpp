// pointer.cpp -- out first pointer variable
#include <iostream>

int main()
{
    using namespace std;
    int updates = 6;                //declare a variable
    int * p_updates;                //declare pointer to an int
    p_updates = &updates;           // assign address of int to pointer

    cout << "values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;
    // p_updates is a pointer object whoes value is an address.
    // *p_updates is the object whoes address stored in p_update.
    // the function of * is extract object

    cout << "Addresses: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    *p_updates = *p_updates + 1;
    cout << "now updates = " << updates << endl;
    return 0;
}
