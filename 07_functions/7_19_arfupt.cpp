// 7_19_arfupt.cpp -- an array of function pointers
#include <iostream>
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);

int main()
{
    using namespace std;
    double av[3] = {1112.3, 1542.6, 2227.9};
   
    //pointer to a function
    const double *(*p1)(const double *, int) = f1;
    auto p2 = f2;          // c++11 automatic type deduction
    cout << "using pointers to functions:\n";
    cout << "address values\n";
    cout << (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
    cout << p2(av,3) << ": " << *p2(av,3) << endl;

    // pointers array to a function list
    const double * (*pa[3])(const double *, int) = {f1,f2,f3};
    auto pb = pa;
    cout << "\nusing an array of pointers to functions:\n";
    cout << " address values\n";
    for (int i=0; i<3; i++)
        cout << (*pa[i])(av,3) << ": " << *(*pa[i])(av,3) << endl;
    cout << " address values\n";
    for (int i=0; i<3; i++)
        cout << pb[i](av,3) << ": " << *pb[i](av,3) << endl;

    // what about a pointer to an whoe array of function pointers
    cout << "using pointers to an whole array of pointers:\n";
    cout << " address values\n";
    // easy way to declare pc
    auto pc = &pa;
    cout << (*pc)[0](av,3) << ": " << *(*pc)[0](av,3) << endl;
    // hard way to declare pd
    const double * (*(*pd)[3])(const double *, int) = &pa;
    // store return value in pdb
    const double * pdb = (*pd)[1](av,3);
    cout << pdb << ": " << *pdb << endl;
    // alternative notation
    cout << (*(*pd)[2])(av,3) << ": " << *(*(*pd)[2])(av,3) << endl;
    return 0;
}

// toy functions
const double * f1(const double * ar, int n)
{
    return ar;
}
const double * f2(const double ar[], int n)
{
    return ar+1;
}
const double * f3(const double ar[], int n)
{
    return ar+2;
}

