// stock10.cpp -- Stock class with constructors, destructor added
#include <iostream>
#include "stock10.h"

// constructors (verbose version)
Stock::Stock()       //default constructor
{
    std::cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

//custom constructor
Stock::Stock(const std::string & co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    company = co;

    if (n<0)
    {
        std::cout << "number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock()    //verbose class destructor
{
    std::cout << "Bye, " << company << "bye\n";
}

//other method
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "number of share can't be negative, can't transact";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "number of shares can't be negative";
    }
    else if (num > shares)
    {
        cout << "you can't sell more than you have";
    }
    else
    {
        shares -=num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    using std::cout;
    cout << "company: " << company << " shares: " << shares << "\n";
    cout << "share price: $" << share_val << "\n";
}
