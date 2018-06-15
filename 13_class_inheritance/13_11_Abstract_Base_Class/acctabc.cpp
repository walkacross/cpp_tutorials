// acctabc.cpp -- bank account class method
#include <iostream>
#include "acctabc.h"
using std::cout;
using std::ios_base;
using std::endl;
using std::string;

//abstract base class
AcctABC::AcctABC(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if (amt < 0)
        cout << "no negetive.\n";
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

// protected method for formatting
AcctABC::Formatting AcctABC::SetFormat() const
{
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr =  cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting & f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

// brass method
void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "no negative.\n";
    else if  (amt < Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "amount withdraw exceeds you balance. cancel..\n";
}

void Brass::ViewAcct() const
{
    cout << "Brass client : " << FullName() << endl;
    cout << "account number: " << AcctNum() << endl;
}

BrassPlus::BrassPlus(const string & s, long an, double bal, double ml,
                     double r) : AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : AcctABC(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    cout << "client: " << FullName() << endl;
    cout << "maximum load: $" << maxLoan << endl;
    cout << "owed to bak: $" << owesBank << endl;
}

void BrassPlus::Withdraw(double amt)
{
    double bal = Balance();
    if (amt < bal)
        AcctABC::Withdraw(amt);
    else if (amt < bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * ( 1.0 + rate);
        cout << "bank advance" << advance << endl;
        cout << "fiannce charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "credit limit exceed.\n";
}
