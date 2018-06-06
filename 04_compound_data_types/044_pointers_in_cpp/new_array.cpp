// new_array.cpp -- using the new operator for arrays
#include <iostream>

int main()
{
    using namespace std;
    double * p3 = new double [3];    // space for 3 doubles
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    
    cout << "p3[1] is " << p3[1] << ".\n";
 
    p3 = p3 + 1;                     // increment the pointer, ok for pointer, wrong for array
    // add 1 to p3 cause it to point to the second element instead of the first.subtracting one takes the pointer back to its origin values so that the program can provide delete [] with the correct address.
    cout << "now p3[0] is " << p3[0] << ".\n";
    cout << "p3[1] is " << p3[1] << ".\n";
    
    p3 = p3 - 1;                     //point back to beginning
    delete [] p3;                    // free the memory
    return 0;

}
