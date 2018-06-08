// 7_13_strctptr.cpp -- function with pointer to structure argument

#include <iostream>
#include <cmath>

struct polar     // subclass struct
{
    double distance;      
    double angle;
};

struct rect
{
    double x;
    double y;
};

// prototype
void rect_to_polar(const rect * pxy, polar * pda);
void show_polar(const polar * pda);

int main()
{
    using namespace std;
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        rect_to_polar(&rplace, &pplace);   //pass addresses
        show_polar(&pplace);               // pass address
        cout << "Next two numbers(q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}

void show_polar(const polar * pda)
{
    using namespace std;
    const double Rad_to_deg = 57.296;
 
    cout << "distance = " << pda->distance;
    cout << ", angle = " << pda->angle * Rad_to_deg;
    cout << " degrees\n";
}

void rect_to_polar(const rect * pxy, polar * pda) 
// output as a parameter, assign it through by passing-by-address
{
    using namespace std;
    pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
    pda->angle = atan2(pxy->y, pxy->x);
}
