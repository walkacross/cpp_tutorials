// external.cpp -- external variables
// compile with support.cpp

#include <iostream>
using namespace std;

// external variable
double warming  = 0.3;    // warming defined

// function prototype
void update(double dt);
void local();

int main()
{
                  //use glabal variable
    cout << "global warming is " << warming << " degrees.\n";

    update(0.1);       // call functions to change warming
    cout << "global warming is " << warming << " degrees.\n";

    local();          //call function with local warming
    cout << "global warming is " << warming << " degrees.\n";
    return 0;
}
