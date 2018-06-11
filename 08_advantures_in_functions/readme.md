# 1 Reference Variable
A reference is an alternative name, for a previous defined variable. you can use refer_var_name or var_name interchangeably to represent that variable.

the main use for a reference variable is as a formal argument to a function. if you use a reference as an argument, the function works with the original data object(passing-by-reference) instead of with a copy(passing-by-value).

## 1.1 reference creation and basic usage
### create a reference variable
c/c++ use the & symbol to indicate the address of a variable. c++ assigns an additional meaning to the & symbol and presses it into service for declaring rederences.
~~~
int rats;
int & rodents = rats;    //make rodents as alias for rates variable
                         // must: declaration with initialization
~~~
in this context, & is not the address operator. instead. it serves as part of the type identifier. just as int * in a declaration means pointer-to-int, int & means reference-to-int.

the referebce deckaration allows you to use rats and rodents interchangeably; bother refer to the same value and the same memory location.

see 8_2_firstref.cpp

### variabel, reference and pointer
~~~
int rats = 101;
int & redoents = rats;    //reodents a reference
int * prats = &rats;     // prats a pointer
~~~
* you could use the expression rodents and *prats interchangeably with rats
* use the expressions &rodetns and prats interchangeably with &rats

### passing-by-value, passing-by-reference, passing-by-pointer
see example: 8_4_swaps.cpp

why this work?
Earlier, I said you should initialize a reference variable when you define it.
**A function can initializes its paramters with argument values from the function call.**. so reference function arguments are initialzed to the argument passed by the function call. that is, the following function call initialzes the formal parameter a to wallet and the formal parameter b to wallet2:
~~~
swapr(wallet1, wallet2);
~~~

## 1.2 Reference properties and oddities
### 1.2.1 temporay variables, reference arguments and const
the compilier generates a temporary varables in two kinds of situation:
* when the actual argument is the correct type but isn't an lvalue
* when the actual argument is of the wrong type, but it's of a type that can be converted to the correct type

> what is an lvalue? an argument that's an lvalue is a data object that can be referenced by address. for example, a variable, an array element, a structure member, a referce, and a derederenced pointer are lvalue.
> non-lvalue include literal constant and expressions with multiple terms.

~~~
double refcube(const double &ra)
{
    return ra*ra*ra
}

double side = 3.0;
double * pd = &side;
double & rd = side;
double lens[4] = {1.0,2.0,5.0,12.0};
long edge = 5L;

double c1 = refcube(side);            // ra is side
double c2 = refcube(lens[2]);         // ra is lens[2]
double c3 = refcube(rd);              // ra is rd is side
double c4 = refcube(*pd);             // ra is *pd is side

double c5 = refcube(edge);            // ra is temporary variable
double c6 refcube(7.0);               // ra is temporary variable, argument not lvalue 
double c7 = refcube(side+10.0);       // ra is temporary variable, argument not a lvalue
~~~
in short, if the intent of a function with reference argument is to modify variables passed as arguments, situatio that create temporary variables will thwart that purpose.

### 1.2.2 rvalues
c++11 introduce a second kind of reference, called an rvalue reference, that ban refer to an rvalue. it declared using &&:
~~~
double && rref = std::sqrt(36.00);      // not allowed for double &
double j = 15.0;
double && jref = 2.0*j + 18.5;
std::cout << rref << "\n";    //display 6.0
std::cout << jref << '\n';    //sisplay 48.5
~~~
the rvalue reference was introduced maily to help library designers provide more efficient implementations of certain operations. the origin reference type (the one &) is now called an lvalue reference.

## 1.3 using reference with structure
the method for using a reference to a structure as a function parameter is the sme as the method using a rederence to a basic variable:

see example 8_6_strc_ref.cpp

## 1.4 using reference with a class objecet
 to learn

## 1.5 when to use reference argument
there are three main reason for using reference argumentl:
* to allow you to alter a data object in the calling function
* to speed up a program by passing a reference instead of an entire data object
the sencond reason is more import for larger data object, such as structure and class object.


when should you use a reference? use a pointer? pass-by value?
some guidelines:
### A function uers passed data wieh modifying it:
* if the data object is small, such as a built-in data type or a small structure, pass it by value.

* if the data object is an array, use a pointer because that's your only choice. make the pointer a pointer to const.

* if the data object is a good-sized structure, use a const pointer or a const reference to increase program efficiency. you save the time and sapce to copy a structure or a class design. **make the pointer or reference const**

* if the data object is a class object, use a const reference. the semantic of class design often require using a reference, which is the main reason c++ added this feature.

### A function modifies data in the calling function:
* if the data object is a built-in data type, use a pointer.
* if the data object is an array, use your only choice: a pointer.
* if the data object is a structure, use a reference or a pointer.
* if the data object is a class object, use a reference.

# 2 default arguments
how to establish a default? you must the function prototype.
~~~
char * left(const char * str, int n = 1);
~~~
* you want the function to return a new string, so its type a char*, or a pointer-to-str.
* you want to leave the original string unaltered, so you use the const qualitier for the first argument.
* you want n to have a default value of 1, so you assign that value to n. a default argument value is an initialization value.

when you use a function with an argument list, you must add default from right to left.
~~~
int harpo(int n, int m=4, int j = 5);   //valid
int chico(int n, int m=6, int j);    // invdlid
~~~

# 3 function overloading
function polymorphism is a neat c++ addition to c's capabilities. whereas default argument let you call the same function by using varying numbers of argument, fucntion polymorphism, also called function overloading, let you use multiple functions share the same name.

the key to function overloading is a function's argument list, also called the function signature. if two functions use the same number and types of argument in the same order, they have the same signature.

c++ enables you define two functions by the same name, provided that the functions have different signatures. the signature can differ in the number of aruments or int the type of arguments, or both.
~~~
void print(const char * str, int width);    //#1
void print(double d, int width);        //#2
void print(long l, int width);          //#3
void print(int i, int width);           //#4
void print(const chat *str);            //#5
~~~
when you use a print() function, the compilier matches you use to the prototype that that the same signature.

## 3.1 signature difference
(1) keep in mind that the signature, not the fucntion type, enables function overloading.
~~~
long gronk(int n ,float m);    //same signature,
double gronk(int n ,float m);  // hence not allowed
~~~

you can have different return types, but only if the signatures are also different
~~~
long fronk(int n, float m);    //different signatures,
double gronk(float n , float m) // hence allowed
~~~

(2) some signature that appears to be different from each pther nonetheless cant't coexist
~~~
double cube(double x);
double cube(double & x);
~~~
you might think this is a place you could use function overloading because the function signature appear to be different. but considering things from the conpilier's standpoint. suppose you have a code like this:
~~~
sout << cube(x)
~~~
compiler has no way of knowling which function to use.

(3)the function-matching process does discriminate between const and non-const varibale
~~~
void dribble(char * bits);    //regular pointer
void dribble(const char *cbits); //const pointer

const char p1[20] = "how's the weather?";
char p2[20] = 'how's businiess';
dribble(p1);              // dribble(const char *)
dribble(p2);              // dribble(char *)
~~~

## 3.2 overloading refernece parameters
~~~
voild stove(double & r1);       //matches modifiable lvalue
void stove(const double & r2);  // matchs const lvalue
void stove(double && r3);       // match rvalue
~~~
this allows you to customize the bahavior of a function based on the lvalue, const, or rvalue nature of the argument:
~~~
double x = 55.5;
const double y = 32.0;

stove(x);     //call stove(double &)
stove(y);     //call stove(const double &)
stove(x+y);   //calls stove(double &&)
~~~

## 3.3 when to use function overloading
you should reserve function overloading for functions that perform basically the same task but with different forms of data.

## 4 function template
a function template is a generic fucntion description; that is , it defines a function in terms of a generic type for which a specific type, such as int or ouble, can be substituted. because templates let you program in terms of a generic type instead of a specific type. the process is sometimes termed generic programming.

function templates enbale you to define a function interms of any arbotrary type. for example, you can set  up a swapping template like this:
~~~
template <typename AnyType>
void Swap(AnyType &a, AnyType &b)
{
    AnyType temp;
    temp = a;
    a= b;
    b = temp;
}
~~~
understand what is function overloading, function templates, and function template overloading
