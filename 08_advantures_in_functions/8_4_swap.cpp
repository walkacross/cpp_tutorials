// 8_4_sawp.cpp -- swaping with references and with pointer
#include <iostream>
void swapv(int a, int b);     // a,b, are new variables
void swapr(int & a, int & b);  // a,b,are aliases for ints
void swapp(int * p, int * q);  // p,qare address of ints

int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "tring to use pass-by-value:\n";
    swapv(wallet1, wallet2);      //pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;
    
    // passing-by-reference
    cout << "using references to swap contents:\n";
    swapr(wallet1, wallet2);      // passing variabels
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "using pointers to swap contents again:\n";
    swapp(&wallet1, &wallet2);  //passing address of variable
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;
    
    return 0;
}

void swapv(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapr(int & a, int & b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapp(int * p, int * q)
{
    int temp; 
    temp = *p;
    *p = *q;
    *q = temp;
}
