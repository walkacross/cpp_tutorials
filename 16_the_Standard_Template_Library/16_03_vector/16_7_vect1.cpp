// vect1.cpp -- intrducing the vector template
#include <iostream>
#include <string>
#include <vector>

const int NUM = 5;

int main()
{
    using std::vector;
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<int> ratings(NUM);
    vector<string> titles(NUM);
    cout << "you will do exactly as told, you will enter\n" << NUM << " book titles and you rating (0-10). \n";

    int i;
    for (i=0; i < NUM; i++)
    {
        cout << "enter title #" << i+1 << ": ";
        getline(cin, titles[i]);
    
        cout << "enter you rating (0-10): ";
        cin >> ratings[i];
        cin.get();
    }
   
    cout << "thank you. you enter the following: \n" << "Rating\tBook\n";
    for (i=0; i < NUM; i++)
    {
        cout << ratings[i] << "\t" << titles[i] << endl;
    }
    return 0;
}
