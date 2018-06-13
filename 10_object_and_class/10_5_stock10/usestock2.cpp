// usestock2.cpp -- using the Stock class
// compile with stock10.cpp
#include <iostream>
#include "stock10.h"

int main()
{
  {
      using std::cout;
      cout << "using constructors to create new object\n";
      Stock stock1("NanoSmart", 12, 20.0);  //syntax1: call the constructor implicitly
      stock1.show();
    
      Stock stock2 = Stock ("Boffo object", 2, 2.0); // symtax2: call explicitly
      stock2.show();

      cout << "assigning stock1 to stock2:\n";
      stock2 = stock1;
      cout << "Listening stock1 and stock2:\n";
      stock1.show();
      stock2.show();

      cout << "using a constructor to reset an object\n";
      stock1 = Stock("NIfty foods", 10, 50.0);    //temp object
      cout << "Revised stock1:\n";
      stock1.show();
      cout << "done\n";
  }
  return 0;
}
