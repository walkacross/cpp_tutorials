// usebrass1.cpp -- testing bank account classes
// compile with brass.cpp
#include <iostream>
#include "brass.h"

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("HHHH,HI", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;

    cout << "depositing $1000 into the Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout << "new balance: $" << Hoggy.Balance() << endl;
    cout << "withdrawing $4200 form the Piggy Accout:\n";
    Piggy.Withdraw(4200.00);
    cout << "Piggy balance: "<< Piggy.Balance() << endl;

    cout << "withdrawing $4200 from the Hoggy account:\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();
 
    return 0;
}
