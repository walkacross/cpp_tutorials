<center>storage duration, scope and linkage</center>
c++ uses three separate schemes(fou c++11) for storing data, and the schemes differ in how long they preserve data in memory.
* automatic storage duration
* static storage duration
> they persist for the entire time a program is running. c++ has 3 kinds of static storage duration variables:(1) static duration, external linkage; (2) static duration, internal linkage;(3) static duration, no linkage.
* thread storage duration(c++11)
* dynamic storage duration
> Memory allocated by the *new* operator persists until it is freed with the *delete* operator or until the program ends, whichever comes first. this memory has dynamic storage duration and somethings is termed the free storage or the heap.which not controlled by the scope and linkage rules.


# scope and linkage
## auto stotage duration
## static duration variable
you can use an external variable with external linkage to share data object in the same address among different parts of a multi program.

you can use a static variable with internal linkage to share data among functions found in just one file.
### staic duration, external linkage
~~~
//erternal.cpp
double warming = 0.3;    //global variable

// support.cpp
extern double warming;   // use warming from external.cpp
~~~
### static duration, internal linkage
~~~
// file1
int errors =20

// file2
int errors = 5            // invalid
static int errors = 5  // valid, know to file2 only
~~~
### static duration, on linkage
see example static.cpp

## function and it linkage
~~~
static int private(double x);  //function prototype
static int private(double x)
{
   ....                        // function definition
}
~~~

##  storage schemes and dynamic allocation
dynamic memory is controlled by the *new* and *delete* operators, not by the scope and linkage rules. thus, dynamic memory can be allocated from one function and freed from another functions.

### 1 initialization with the *new* operator
(1) create and initialze storage for one of the scalar built-in types:
~~~
int *pi = new int (6);    //*pi set to 6
double * pd = new double (99.99);
~~~
(2) to initialize an orinary structure or an array
~~~
struct where {double x; double y; double z;};

where * one = new where {2.5,5.3, 7.2;
int * ar = new int [4] {2,3,4,5};   // c++11
~~~

### 2 regular new and placement new operator
normally, the new operator has the responsibility of finding in the heap a blovk of memory that is large enough to handle the amout of memory you request.

the new operator has a varition, called placement new, that allow you to specify the location to be used.
# Specifiers and qualifiers
## storage class specifiers
* register
* static
* extern
* thread_local(added by c++11)
* mutable
## Cv-quanlifier
* const  : memory, after initialized, should not be altered by a program
* volatile : the value in a momory location can be altered even thought nothing in the program code modifies the contents.

# namespace
## terms
* declarative region, potential scope and scope
## using declarations and using directives
~~~
// using declarations
using std::cout

// using directives
using namespace std
~~~

~~~
namespace Jill
{
    double bucket(double n) { ...};
    double fetch;
    struct Hill {...};
}

char fetch;               //global namespace

int main()
{
    using namespace Jill;  //import all namespace names
    Hill Thrill;           // create a type Jill::HIll structure
    double water = bucket(2);  //use JIll::bucket();
    double fetch;          // not an error; hides JIll::fetch
    cin >> fetch;          // read a value into the local fetch
    cin >> ::fetch;        // read a value into global fetch, use scope-resolution operator
    cin >> Jill::fetch;    // read a value into Jill::fetch
}
~~~

in main(). the name Jill::fetch is placed in the local namespace. It doesn't have local scope, so it doesn't override the global fetch.

but the locally declared fetch hides both Jill::fetch and the global fetch.

## guideline
* using variables in a named namespace instead of using external global variables.

* use variables in anunnamed namespace instead of using static global variables.

* if you develop a library of functions or classes, place them in a namespace. indeed, c++ currently already calls for placing stantard library functions in a namespace called std. this extends to functions brought in from C.

* don't using directives in header file;
* if you use a using directive, place it after all the preprocessor #include directives.
* preferentially import names by using the scope-resolution operator or a using declaration.
* preferentially use local scope instead of global scope for using declarations.
