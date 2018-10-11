// functor_convert.cpp --  convert function with two argument to one-argument functions object
#include <iostream>

template <class T>
bool tooBig(const T & val, const T & lim)
{
    return val > lim;
}

template <class T>
class TooBig2
{
private:
    T cutoff;
public:
    TooBig2(const T & t) : cutoff(t) {}
    bool operator()(const T & v) {return tooBig<T>(v, cutoff);}
};

int main()
{
    TooBig2<int> tB100(100);
    int x;
    std::cin >> x;
    if (tB100(x))
        std::cout << "larger than 100";
    else
        std::cout << "less than 100";
    return 0;
}
