// brass.cpp -- bank class method
#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;

//format stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setFormat();
void restore(format f, precis p);

//base class
Brass::Brass(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "no negative.\n";
    else
        balance += amt;
}

// Withdraw method in declaration is a virtual method, but here...
void Brass::Withdraw(double amt)
{
    // set up ###.## format
    format initialState  = setFormat();
    precis prec = cout.precision(2);
   
    if (amt < 0)
        cout << "no negative\n";
    else if (amt <=balance)
        balance -= amt;
    else
        cout << "withdraw aamount of $ " << amt << "exceeds your balance.\n";
    restore(initialState, prec);
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    cout << "clinet: " << fullName << endl;
    cout << "balance: " << balance << endl;
}

// derived method
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml,
                     double r) : Brass(s,an,bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba)
                                             // use implicit copy constructor
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
} 

//redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
    Brass::ViewAcct(); //display base portion
    cout << "maximum loadn: $" << maxLoan << endl;
    cout << "Owed to bank: $ " << owesBank << endl;
}

// redefine how withdraw() works
void BrassPlus::Withdraw(double amt)
{
    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout << "Credict limit exceeded. transaction canceled.\n";
}

format setFormat()
{
    //set up
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}
