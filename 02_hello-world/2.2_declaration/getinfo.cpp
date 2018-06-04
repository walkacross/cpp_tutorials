// getinfo.cpp -- decalaration,input and output
#include <iostream>

int main()
{
    using namespace std;

    int carrots;

    cout << "how many carrots do you have" << endl;
    cin >> carrots;  //input and assignment
    cout << "here are tow more.";
    carrots = carrots + 2; //assignment rather than ==
    cout << "Now you have " << carrots << " carrots." << endl; //convert int to str auto
    return 0;
}
