// smrtptrs.cpp -- using three kinds of smart pointers
// requires support of c++11 shared_ptr adn unique_ptr
#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
    std::string str;

public:
    Report(const std::string s) : str(s)
        { std::cout << "object created\n";}
   
    ~Report() { std::cout << "object deleted\n";}
    void comment() const { std::cout << str << "\n";}
};

int main()
{
    {
        std::auto_ptr<Report> ps (new Report("using suto_ptr"));
        ps->comment();
    }

    {
        std::unique_ptr<Report> ps (new Report("using unique_ptr"));
        ps->comment();
    }

    {
        std::shared_ptr<Report> ps (new Report("using shared_ptr"));
        ps->comment();
    }
    return 0;
}
