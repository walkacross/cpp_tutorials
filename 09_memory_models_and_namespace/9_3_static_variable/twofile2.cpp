// twofile2.cpp -- varibales with internal and external linkage
#include <iostream>
extern int tom;    //tom defined elsewhere
static int dick = 10;    //overides external dick
int harry = 200;         //external variable definition, no conflict with twofile harry

void remote_access()
{
    using namespace std;
    cout << "remote_access() reports the following addresses:\n";
    cout << &tom << " =&tom, " << &dick << " =&dick, ";
    cout << &harry << " =&harry\n";
}