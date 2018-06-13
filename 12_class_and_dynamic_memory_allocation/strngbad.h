// strngbad.h -- flawed string class definition
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_
class StringBad
{
private:
    char * str;            //pointer to string
    int len;               // length os tring
    static int num_strings;  // number of objects
                           // A program creates only one copy of a static class variable, regrardles of the number of objects created. that is a static member of shareed among all objects of that class
public:
    StringBad();          //default constructor
    StringBad(const char * s);  //constructor
    ~StringBad();
    // friend function
    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);  };
#endif
