// structure.cpp -- a simple structure
#include <iostream>
struct inflatable //structure declaration
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;
    inflatable guest = 
    {
        "Glorious Gloria", // name value
        1.88,
        29.99
    };  // guest is a structure object of type inflatable
    
    inflatable pal =
    {
        "Audacious Arthur",
        3.12,
        32.99
    };
    
    cout << "Expand yout guest list with " << guest.name;
    cout << " and " << pal.name << "!\n"; // pal.name is the member of the pal
    cout << "you can have both for $";
    cout << guest.price + pal.price << "!\n";
    return 0;
}
