# string in cpp

## 1 C-style string
C-style strings have s special featyre: the last character of every string is the null character. this character, writtern \0, is the character with ASCII code 0, and it serves to mark the string's end.
~~~
char bird[11] = "Mr. Cheeps"; // the \0 is understood
char fish[] = "Bubbles";  // let the compiler count
~~~

## 2 c++ string library
~~~
#include <string>

int main()
{
    using namespace std;
    char charr1[20];               // create an empty array
    char charr2[20] = "jaguar";    // create an initialed array
    string str1;                   // create an empty string object
    string str2 = "panther";       // create an initialzed string
}
~~~

# assignment,concatenating and appending of string
~~~
string str1;
string str2 = "panther";
str2 = str2

string str3;
str3 = str1 + str2;
str1 += str2;
~~~
