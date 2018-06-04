// custom_func.cpp -- convert stone to pounds
#include <iostream>
int stonetolb(int); // function prototype - by declare function

int main()
{
    using namespace std;
    int stone;
    cout << "Enter the weight in stone: ";
    cin >> stone;
    int prouds = stonetolb(stone);
    cout << stone << " stone = ";
    cout << prouds << " pounds." << endl;
    return 0;
}

int stonetolb(int sts)
{
    return 14 * sts;
}
