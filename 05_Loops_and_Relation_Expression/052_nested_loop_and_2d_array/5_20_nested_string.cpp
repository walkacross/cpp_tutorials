// 5_20_nested_loop_string.cpp -- nested loop and 2-D array
#include <iostream>
#include <string>

const int Cities = 3;
const int Years = 2;

int main()
{
    using namespace std;
    const string cities[Cities] = // array of 5 strings
    {
        "Gribble City",
        "San Gribble",
        "New Gribble"
    };
    
    int maxtemps[Years][Cities] = // 2-D array
    {
        {91,99,88},
        {67,83,77}
    };
    
    cout << "maximum temperatures for 2017 - 2018\n\n";
    for (int city = 0; city < Cities; ++city)
    {
        cout << cities[city] << ":\t";
        for (int year=0; year < Years; ++year)
            cout << maxtemps[year][city] << '\t';
        cout << endl;
    }
    return 0;
}
