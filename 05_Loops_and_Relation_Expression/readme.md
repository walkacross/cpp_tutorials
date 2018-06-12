# 1introdution
Computers do more than store data. they analyze, consolidate, rearrange, extract, modify, extrapolate, synthesize, and otherwise manipulate data. To perform their manipulative miracles, program need tools for performing repitive actions. of causse, c++ provide such tools. like *for loop*,*while loop*,*do wile loop*.



# 2 prerequisites
## 2.1 expression and statement
> any value or any valid conbination of values and operators constitute an **expression**. and every c++ expression has a value

~~~
10
22 + 35
x = 20 
 //x =20 is an assignment expression, though evaluating an assignment expression has the side effect of changeing the assignee's value. evaluating the expressio is the primary effect.
x=y=z=0
maid = (cook2=4) +3
~~~

from an expression is a short step: you just add a semicolon.
~~~
age =100  is an expression
age = 100; is a statement, more particular, it is an expression statement.
~~~

## 2.2 Nonexpressions and statement
although it is the rule that adding a semicolon to any expression makes it a statement, the reverse if not true:
~~~
int toad; //is a statement, but int load is not an expression, as it's not a value

egg = int toad * 1000;    //invalid, not an expression
cin >> int toad;          //can't combine declaration with cin
~~~

# 1 for loop
~~~
statement 1
for (init_expr; test_expr; update_expr)
    statement2
statement3
~~~

# 2 for while

~~~
while (test_condition)
    body
~~~

# 3 do while loop
~~~
do
    body
wile (test_expression);
~~~
such a loop always executes at least once because its program flow must pass through the body of the loop before reaching the test.


# the Range-based for loop (c++ 11)
example:
~~~
double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49}
for (double x : prices)
    std::cout << x << std::endl
~~~

to modify array values, you need a different syntax for the loop variable:
~~~
for (double &x : prices)
    x = x * 0.80      // 20% off sale
~~~
# nested loops and two-dimension array
1 initializing a two-dimensional array
~~~
int maxtemps[3][2] = // 2-d array
{
    {96,97},
    {93,95},
    (88,90)
};
~~~

2 using a two_dimensional array
2.1 string class version
~~~
#include <iostream>
#include <string>

const int Cities = 3;
const int Years = 2;

int main()
{
    using namespace std;
    const string cities[Cities] = // array of 5 strings
    {
        "Gribble City",
        "San Gribble",
        "New Gribble"
    };
    
    int maxtemp[Years][Cities] = // 2-D array
    {
        {91,99,88},
        {67,83,77}
    };
    
    cout << "maximum temperatures for 2017 - 2018\n\n";
    for (int city = 0; city < Cities; ++city)
    {
        cout << Cities[city] << ":\t";
        for (int year=0; year < Year; ++year)
            cout << maxtemps[year][city] << '\t';
        cout << endl;
    }
    return 0;
}
~~~

~~~
~~
~~~

# type aliases
c++ has two ways to establish a new name as an alias for a type. One is to use the preprocessor:
~~~
#define BYTE char  //preprocessor replaces BYTE with char
~~~
the preprocessor then replaces all occurrences of BYTE with char when you compile aa program, thus making BYTE an alias for *char*.

the second method is to use the c++ keyword **typedef** to create an alias. For example, to make byte an alias for char, you use this:
~~~
typedef char byte;    // makes byte an alias for char
~~~
here is the general form:
~~~
typedef typeName aliasName;
~~~

~~~
typedef char* byte_pointer;
#define FLOAT_POINTER float*
~~~
