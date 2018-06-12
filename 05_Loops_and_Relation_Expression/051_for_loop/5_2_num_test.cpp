// 5_2_num_test.cpp -- use numeric test in for loop
#include <iostream>

int main()
{
    using namespace std;
    int limit;
    cout << "enter the starting contdown value: ";
    cin >> limit;
    int i;
    
    for (i = limit; i; i--)  //quit when i s 0
        cout << "i = " << i << '\n';
    cout << "done now that i = " << i << "\n";
    return 0;
}
