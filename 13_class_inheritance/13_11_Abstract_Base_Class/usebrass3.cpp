// usebrass3.cpp
// compile with acctabc.cpp
#include <iostream>
#include <string>
#include "acctabc.h"
const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    AcctABC * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "enter client's account name: ";
        getline(cin, temp);
        cout << "enter client's account number: ";
        cin >> tempnum;
        cout << "enter opening balance: $";
        cin >> tempbal;
        cout << "enter 1 for brass or 2 for brassplus account: ";
        while (cin >> kind &&(kind != '1' && kind != '2'))
            cout << "enter either 1 or 2: ";
        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "enter the overdraft limit: $";
            cin >> tmax;
            cout << "enter interest rate: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i=0; i< CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    
    for (int i=0; i<CLIENTS; i++)
    {
        delete p_clients[i]; //free memory
    }
    cout << "Done.\n";
    return 0;

}
