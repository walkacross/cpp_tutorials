// usett0.cpp -- using a base class
#include <iostream>
#include "tabtenn0.h"

int main()
{
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("chunk", "bralizad", false);
    RatedPlayer rplayer1(1140,"tara", "cccc", true);
    rplayer1.Name();    //derived object use base method
    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    player1.Name();
     if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    cout << "name: ";
    rplayer1.Name();
    cout << "; rating: " << rplayer1.Rating() << endl;

    //
    RatedPlayer rplayer2(1112,player1);
    cout << "name: ";
    rplayer2.Name();
    cout << "; rating: " << rplayer2.Rating() << endl;
    
    return 0;

}
