// lotto.cpp -- probability of winning
#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;
    double total, choices;
    cout << "enter the total number of choices on the game card and the number of picks allowed:\n";

    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "you hace one chance in ";
        cout << probability(total, choices);   // compute the odds
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye\n";
    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;    //here come some local variable
    long double n;
    unsigned p;
   
    for (n=numbers, p = picks; p >0; n--, p--)
        result = result * n / p;
    return result;
}
