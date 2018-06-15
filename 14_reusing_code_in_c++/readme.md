<center>reusing code in c++</center>

# has-a relationship with other class
~~~
#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;      // constained object
    ArrayDb scores;        // constained object
public:
    Student() : name("NULL Student"), scores() {}
    
    explicit Student(const std::string & s) : name(s), scores() {}
    explicit Student(int n): name("Nully"), scores(n) {}

    Student(const std::string & s, const ArrayDb & a) : name(s), scores(a) {}
    Student(const chat * str, const double * pd, int n) : name(str), scores(pd,n) {}

    ~Student() {}
}
~~~

# 2 public, private and protected inheritance
# 3 multiple inheritance

