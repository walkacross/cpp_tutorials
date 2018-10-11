#include "hello.h"    //internal library
#include <api.h>     //external library
#include <iostream>   //in-built library


int main()
{
    hello("world");
    int x = ADD (2, 3);
    std::cout << "2 + 3 is " << x << std::endl;
    return 0;
}
