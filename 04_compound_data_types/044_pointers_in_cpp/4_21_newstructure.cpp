// 4_21_ne_structure.cpp -- using new with a structure
#include <iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;
    inflatable * ps = new inflatable;    //allocate memory for structure
    
    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20);               // method 2 for member access
    
    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume;                  // method 1 for member access

    cout << "Enter proce: $";
    cin >> ps->price;

    cout << "name: " << (*ps).name << endl;  //method 1
    cout << "volume: " << ps->volume << " cubic feet\n"; //method 2
    cout << "price: " << ps->price << endl;
    
    delete ps;                           // free memory used by new
    return 0;
}
