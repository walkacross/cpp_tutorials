<center>class inheritance</center>

# 1introduction

## 1.1 simple example
## 1.2 access right

## 1.3 static and dynamic binding
interpreting a function to be called in the source code as execution a particular block of function code is termed *binding the function name*

### 1.3.1 pointer and reference Type compatibility
~~~
double x =  2.5;
int * pi = &x;  // invalid assignment, mismatched pointer
long & rl = x;  // invalid assignemnt
~~~

however,a reference pr a pointer to a base class can refer to a derived class object without using an explicit type cast.
~~~
BrassPlus dilly ("AAA", 2455645, 2000);
Brass * pb = &dilly; //ok
Brass & rb = dilly;
~~~

Question?
~~~
BrassPlus ophelia;
Brass * bp;
bp = &OPHELIA;
BP->ViewAcct();  //which version?
~~~
if ViewAcct() is not declared as *virtual method* in the base class,the compiler can bind  bp->ViewAcct() goes by the pointer type(Brass *) and invokew Brass::ViewAcct(). in short, the compiler uses static binding for non-virtual method.

if ViewAcct() is declared as Virtual in the base class, bp->ViewAcct() goes by the object tupe(BrassPlus) and invoke BrassPlus::ViewAcct(). in short, the compiler uses dynamic binding for virtual methods.

### 1.3.2 why two kinds of Binding and Why Static Is the default

# 2Abstract Base Class
An ABC demands that its pure virtual functions be overridden in any concrete derived classes -- forcing the derived class to obey the rules of interface the ABC has set. this model is common in component-based programming paradigms, in which the use of the ABCs allows the component designer to create an "interface contact" where all components derived from the ABC are guaranteed to uphold at least the common functionality specified by the ABC.

# 3inheritance and dynamic memory allocation

# 4Class Design Review
## 4.1 Member Functions that the compiler generates for you
### constructor conserdieration
(1) if you don't define any constructors, the compiler defines a default constructor for you.

(2) the base-class constructor can't be inherited.

(3) if you write a derived-class constructor without explicitly invoking a base-class constructor in the member initializer list, the compilier use the base-class default constructor to construct the base class portion of the new object.
### copy operators
### assignment operators

## 4.2passing an object bu value Versus passing by a reference
in general, is you write a function using an object argument, you should pass the object by reference rather than by value.

one reason for this is efficiency
> passing an object by value involves generating a temporary copy, which means calling the copy constructor and then later calling the destructor.[if the function doesn't modify the object, you should declar the argument as a *const* reference].

another reason for passing objects by reference is that, in the case of inheritance using virtual functions.

## 4.3 returning an object versus returning a reference
sometimes a method must return an object, but if it isn't necessary, you should use a reference instead.

~~~
Star noval(const Star &);    //returns a Star object
Star & noval(const Star &);  //returns a reference to a Star
~~~
returning an object involves the time cost of calling a copy constructor to generate the copy and the time cost of calling the destructor to get rid of the copy. returning a reference asaves time and momoty use.
(1)
as a rule thumb, if a function returns a temporary object create in the function, you shouldn't use a reference.
~~~
Vector Vector::operator+(const Vector & b) const
{
     return Vector(x+b.x, y+b.y);
}
~~~

(2) if a function returns an object that was passed to it via a reference or pointer, you should return the object by reference.
~~~
const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;        //argument object
    else
        return *this;     //invoking an object
}
~~~

## 4.4 using const
(1)
you can use it to guarantee that a method doesn't modify an argument
~~~
Star::Star (const char * s) {...} //won't change the string to which s points
~~~

(2) you can use const to guarantee that a method won't modify the object that invokes it.
~~~
void Star::show() const {...};   //won't change invokeing object
~~~

(3) normally, a function that returns a reference can be on the left side of an assignment statement, which really means you can assign a value to the object referred to. but you can use const to ensure that a reference or pointer return value can't be used to modify data in an object
~~~
const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
~~~
here the method returns a reference either to this or to s. because this and s are both declared const, the function is not allowed to change them, which means the returned rederence also must be declared const.

**note**: if a function declares an argument as a regerence or pointer to a const.it cannot pass along that argument to another function unless taht function alse guarantees not to change the argument.

## 4.5 Virtual method considerration
when you design a base class, you have to decide whether to make class methods virtual.

if you wnt to derived class to be able o refine a method, you define the method as virtual in the base class. this enable dunamic binding.

if you don't want the method to be redefined, you shouldn't make it virtual.
