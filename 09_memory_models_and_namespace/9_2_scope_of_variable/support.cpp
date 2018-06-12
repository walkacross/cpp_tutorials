// support.cpp -- use external variable
// compile with external.cpp
#include <iostream>
extern double warming;    //use warming from another file

//function prototype
void update(double dt);
void local();

using std::cout;

void update(double dt)    // modify global variable
{
    extern double warming;  //optional redeclaration
    warming +=dt;           // use global warming
    cout << "updating global warming to " << warming;
    cout << " degrees.\n"; 
}

void local()         // use local variable
{
    double warming = 0.8;       //new variable hides external one
  
    cout << "local warming  = " << warming << " degrees.\n";
    cout << "but global warming = " << ::warming;
    cout << " degrees.\n";
}
