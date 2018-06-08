# 1introduction
you must do the following:
* Provide a function definition
* Provide a function prototype
* Call the function

# 2 defining a function
you can group functions into two categories: thoes that don't have return values and thoes that do:  functions without return values are termed type **void function** and have the following general form:
~~~
void functionName(parameterList)
{
    statement(s)
    return;            // optional
}
~~~

a function with a return value produces a value that it returns to the function that called it.
~~~
typeName functionName(parameterList)
{
    statement(s)
    return value;       // value is tyoe cast to typeName
}
~~~
**the return value cannot be an array. everything else is possble - integer, floating-point numbers, pointers, and even structures and objects** (interestingly, even though a C++ function can't return an array directly, it can return a struct or object that contains an array)

# 2.1
prototype syntax
~~~
double cube(int x);  //valid
double cube(int);    //valid
void cheet(int );    //valid
~~~

## 2.2 why compile need function prototype?
when the function finish its calculation, it places its return value at some specified location --perhapes in a CPUreister, perhape in memory.

then the calling function, main() in this case, retrieves the value from that location. compiler knows how many bytes to retrieve and how to interpret them because of the existence of function prototype.

# 3 Function Arguments and passing by value

## 3.1 the process of passing arguments
c++ normally passes arguments by value: that means the value of the data object is pass to the function, where it is assigned to a new variable with the same type. and then conduct the function body. disappeared after the function finished.

in the situation of passing-by-value: parameter is just a copy of the argument.

see example 7_4_lotto.cpp

## 3.2 pointer and const
you can use const keyword two different ways with pointers
(1) make the pointer itself constant, and that prevent  you from changeing where the pointer points.

you cant change the value indirectly via the pointer: this declaration for pt doesn't necessarily mean that the value it points to is really a constant
~~~
int age = 39;
const int * pt = &age
~~~
~~~
*pt += 1;    //invalid because pt points to a const int
cin >> *pt;  // invalid
~~~
~~~
*pt = 20   // invalid
age =20    //valid, cuz age is not declared to be const
~~~

(2) make a pointer point to a contant object, and that prevent you from using the pointer to change the pointed-to value.
~~~
const float g_earth = 9.80;
const float * pe = &g_earth;   //valid

float * pm = &g_earth;    //invalid: c++ prohibits you from assigning the address of a const to a non-const pointer
~~~

(3) a const pointer to a data object
the const in the fist declaration only prevent you from chaneing the value to which pt points, but it doest prevent you from changing the value of pt itself: that is , you can assign a new address to pt:
~~~
int age =39;
const int * pt = &age;
int sage = 80;
pt = &sage         //valid
~~~

how to avoid this?
~~~
int sloth = 3;
const int * ps = &sloth;        // a pointer to const int
int * const finger = &sloth;    // a const pointer to int
~~~

(4) a const pointer to a const data object
~~~
double trouble = 2.0E30;
const double * const stick = &trouble;
~~~
in this case, both stick and *stick are const.

# 4 Function and Array
see example 7_5_arrfunc1.cpp, but pay attention. it just looks likei right.
why say this?  recall that: C++ interpret an array name as the address of its first element.
~~~
cookies = &cookies[0]
~~~

but why it works? there are a few exceptions to this rule.
* the array declaration uses the array name to label the storage.
* applying *sizeof* to an array name yields the size of the whole array, in bytes.
* applying the address operator to an array name returns the address of the whole array. for example &cookies would be the address of a 32-byte block of memory if int is 4 bytes.

so the arr is actually is address:
~~~
int sum_arr(int * arr, int n)

and then

arr[i] = *(arr+i)
&arr[i] = ar + i
~~~

> why c++ interpret array object as the address of the array's fist element? one reason is : according the pass argument rules, the design decision to use array addresses as argument saves the time and momory need to copy an entire array.

2-D array
~~~
ar2[r][c] = *(*(arr+r) + c)
~~~

explaination
~~~
ar2             // pointer to first row of an array of 4 int
ar2 + r         // pointer to row r
*(ar2+r)        // row r = a pointer to the first int in the row
*(ar2+r) + c    //pointer int number c in row r
*(*(ar2+r)+c)   // the element of ar2 in row r and cloumn c.
~~~

# 5 Function and structure
three ways to pass argument
* passing-by-value : simple but if the data object is large, the space and effort involving in making a copy of a structure can increse memory requirements and slow down the system.

* passing-by-address

* passing-by-reference

## 5.1 pass struct by value
example 5_11_travel.cpp

## 5.2 pass struct by address
you can pass am object by value to a function, in which case the function acts on a copy of the origin object. Alternativelym, you can pass a pointer to an object, which allows the function to act on the original object.

suppose you wnat to save time and space by passing the address of a struct instead of the entire structure.

in the case of structure, three key points:
* when calling the function, pass it the address of the structure rather than the structure itself;
* declaring the formal parameter to be a pointer-to-structure, that is structure *. if the function shouldn't modify the structure, use the const modifier.
* because the formal parameter is a pointer instead of a strcuture. use the indirect membership operator(->) rather than the membership operator(dot).

see example 7_13_strctptr.cpp

# 6 Function and string
# 7 Function and array object
# 8 Pointers to functions
Functions, like data items, have addresses. A function's address is the momory address at which the stored machine language code for the function begins.

it's possible to write a funtion that takes the address of another function as an argument. that enables the first function to find the second function and run it. This approach is more awkward than simply having the fist cuntion call the sencond one directly, but it leaves open the possibility of passing different function addresses at different times. that means the first function ca use different functions at different times.
 
## step1: obtain the address of a function
a function is think(): the function name is its address
~~~
process(think)      // passes address of think() to process()
thought(think())    // passes return value of think() to tought()
~~~

## step2: declaring a pointer to a function
~~~
double pam(int);   //function prototype
double (*pf)(int);  // pf is a pointer points to a function that takes one int argument and that reutrns type double
~~~

~~~
pf = pam    // initialzation: pf now points to the function
~~~

## step3: using a pointer to invoke a function
~~~
double pam(int);
double (*pf)(int);
pd = pam;

double x = pam(4);    // call pam() using the function name
double y = (*pf)(5);  // call pam() using the pointer pf
double z = pf(5);     // also call pam() using the pointer pf
~~~
pointer points to array, struct and function seems have a common functionality: the pointer  can represent the data object itself to some extent.

view about this:
> the name of a function is a pointer to that function. a pointer to that function should at like the name of a function; hence you should use pf() as a function call.

## variations on the Theme of Funtion Pointer
### how to  define  a pointer points to a function with pointer returns?
~~~
const double * f1(const double ar[], int n)
const double * f2(const double [], int)
const double * f3(const double *, int)

const double * (*p1)(const double ar[], int)  # declare pointer-to-function_with_pointer_returns
const double * (*pa)(const double *, int) = f1  # initialization
auto p2 = f2                                    // c++11 automatic type deduction

cout (*p1)(av,3) << " : " << *(*p1)(av,3) << endl;
cout p1(av,3) << ": " << *pa(av,3) << endl;

// the fisrt part is function return object wich is a pointer. so get the value at store at the address. use * operator to these address.

### how to handy to have an array of function pointers?
~~~
const double * (*pa[3])(const double *, int) = {f1,f2,f3}
~~~

* operator precedence ranks [] higher thatn *, *pa[3] says pa is an array of three pointers.
* each of which is a pointer to a function that takes a const double * and int as argument and returns a const double *
* recall the name of an array is a pointer to its first element, so pa is a pointer to a pointer to a function.
* auto pb = pa #pointer array

how to use it to call a function?
~~~
const double * px = (*pa[0])(av,3)
const double * py = pb[1](av,3)
~~~
and you can apply * operator to get the pointed-to double value
~~~
double x = *(*pa[9])(av,3)
double y = *pb[1](av,3)
~~~
**operator precedence ranks [] and () are higher thatn * .**

### how to create a pointer to the whole pointer array?
because the array name pa already is a pointer to a function pointer, a pointer to the array whould be a pointer to a pointer to a pointer
~~~
auto pc = &pa
const double *(*(*pd)[3])(const double *, int) = &pa
~~~
*pd[i] is an array element, which is a pointer to a function

pa is the address of the first element of the array, &pa is the address of the enture array(that is, of block of three pointers). Numerically, pa and &pa may have the same value, but they are different types. 
(1)one partical different is that pa+1 is the address of the next element in the array, whereas &pa+1 is the address of the next block of 12 bytes(assuming addresses are 4 bytes) following the pa array.
(2)another difference is that you dereference pa once to get the value of the first element and you dereference &pa twice to get the same value
~~~
**&pa == *pa == pa[0]
~~~

### combined example 7_19_arfupt.cpp

### simplifying with auto and typedef
(1) auto
~~~
auto pc = &pa  // c++11 automatic type deduction
const double * (*(*pd)[3])[const double *, int) = &pa;   //c++98, do it yourself
~~~

(2)type def
make a alias for a data type
~~~
typedef double real;    // makes real another name for double
~~~

~~~
typedef const double *(*p_func)(const double *, int);    // p_func now a type name

p_func p1 = f1;    // p1 pointes to the f1() function

p_func pa[3] = (f1,f2,f3); //pa an array of 3 function pointer
p_func (*pd)[3] = &pa;     // pd points to an array of 3 function pointers
~~~
not only does typedef save you some tine typing,it makes writing the code less erroe prone, and it makes the program easier to understand
