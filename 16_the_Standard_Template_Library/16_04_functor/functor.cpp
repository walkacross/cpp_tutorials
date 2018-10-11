// functor.cpp -- using a functor
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

template<class T>
class TooBig
{
private:
    T cutoff;
public:
    TooBig(const T &t) : cutoff(t) {}
    bool operator()(const T & v) {return v > cutoff;}
};

void outint(int n)
{
    std::cout << n << " ";
}

int main()
{
    using std::list;
    using std::cout;
    using std::endl;

    TooBig<int> f100(100);  // limit = 100
    int vals[10] = {50,100,90,180,60,210,415,88,188,201};
    list<int> yada(vals, vals + 10);    // range constructor
    list<int> etce(vals, vals + 10);

    cout << "original list:\n ";
    for_each(yada.begin(), yada.end(), outint);
    cout << endl;
    for_each(etce.begin(), etce.end(), outint);
    cout << endl;

    yada.remove_if(f100);            // use a named function object
    etce.remove_if(TooBig<int>(200));   // construct a function object

    cout << "trimmed list:\n";
    for_each(yada.begin(), yada.end(), outint);
    cout << endl;
    for_each(etce.begin(), etce.end(), outint);
    cout << endl;
    return 0;
  
}
