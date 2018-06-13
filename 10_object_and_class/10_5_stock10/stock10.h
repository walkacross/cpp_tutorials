// stock10.h -- stock class declaration with constructor, destructor added
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>

class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = shares * share_val;}   //likw inline func

public:
    //two constructor
    Stock();
    Stock(const std::string & co, long n=0, double pr=0.0);
    //destructor
    ~Stock();
    //method
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

#endif
