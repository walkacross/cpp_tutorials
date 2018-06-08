// calling.cpp -- definition, prototype, and calling a function
#include <iostream>

void simple();      // function prototype

int main()
{
    using namespace std;
    cout << "main() will call the simple() funtion:\n";
    simple();       // function call
       cout << "main() is finished with the simple() function. \n";
    return 0;
}

//function deginition
void simple()
{
    using namespace std;
    cout << "I'm but a simple function.\n";
}
