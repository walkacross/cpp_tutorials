// stacker.cp -- testing the Stack class
#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
    using namespace std;
    Stack st;    //create an empty stack object
    char ch;
    unsigned long po;
    cout << "please enter A to add a purchae prder,\n" << "P to process a PO, o Q to quit.\n";

    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch(ch)
        {
            case 'A':
            case 'a':
                cout << "enter a PO number to add: ";
                cin >> po;            
                if (st.isfull())
                    cout << "stack already full\n";
                else
                    st.push(po);
                break;
            case 'P':
            case 'p':
                if (st.isempty())
                    cout << "stack already empty\n";
                else{
                    st.pop(po);
                    cout << "PO #" << po << "popped\n";
                }
                break;
        }
        cout << "please enter A to add a purchase order,\n" << "P to pop and Q to quit\n";
    }
    cout << "bye\n";
    return 0;
}
