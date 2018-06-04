// sqrt.cpp -- using the built-in library function

#include <iostream>
#include <cmath> // or math.h   old style in c

int main()
{
    using namespace std;
   
    double area;
    cout << "Enter the floor area, in square feet, of you home: ";
    cin >> area;
    double side;
    side = sqrt(area);
    cout << "that's the equivalent of a square " << side << " feet tot the side." << endl;
    cout << "how fascinating" << endl;
    return 0;
}
