// 5_14_timedelay_loop.cpp -- using clock() in a time-delay loop
#include <iostream>
#include <ctime>       // describes clock() function, clock_t type

int main()
{
    using namespace std;
    cout << "enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;  //concert tot clock ticks
    cout << "starting\a\n";
    clock_t start = clock();
    
    while (clock() - start < delay)    // wait until time elapses
        ;                              // note the semicolon
    cout << "done \a\n";
    return 0;
}
