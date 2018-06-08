// 7_8_arrfunc4.cpp -- functions with an array range
#include <iostream>

const int ArSize = 8;
int sum_arr(const int * begin, const int * end);

int main()
{
    using namespace std;
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
   
    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "total cookies eaten: " << sum << endl;

    sum = sum_arr(cookies, cookies+3);  //reassign the value of sum
    cout << "first three eaters ate " << sum << endl;

    sum = sum_arr(cookies+4, cookies+8); //reassign
    cout << "the last four eaten is: " << sum << endl;
    return 0;
}

int sum_arr(const int * begin, const int * end)
{
    const int * pt;
    int total = 0;
    
    for (pt=begin; pt !=end; pt++)
        total = total + *pt;
    return total;
}
