// vegnews.cpp -- using new and delete with classes
// compile with strnbad.cpp
#include <iostream>
using std::cout;
#include "strngbad.h"

void callme1(StringBad &); // pass by reference
void callme2(StringBad);  //pass by valye

int main()
{
    using std::endl;
    { 
        cout << "starting an inner blovk.\n";
        StringBad headline1("Celer stasj at midnight");
        StringBad headline2("leter prey");
        StringBad sports("sporid learsd bows for dollars");

        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline1 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;

        cout << "initializing one object to another:\n";
        StringBad sailor = sports;
        cout << "sailor: " << sailor << endl;
        
        cout << "assign one object otanother:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
       
        cout << "existing the block.\n";
    }
    cout << "end of main() \n";
  
    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "String passed byu value:\n";
    cout << "      \"" << sb << "\"\n";
}
