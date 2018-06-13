<center>Class and dynamic memory allocation</center>

this chapter looks at how to use *new* and *delete* with class and how to deal with some of the subtle problems that using dynamic memory can cause. these topics affect constructor design, destructor, and operator overloading.

# encouter errors when operate custom class
* pass object as a value
* copy: className new_object = old_object
* assignment: knot = old_object

these problems stem from *special member function*, as c++ automatically provide the following member functions
* A default constructor if you define no constructor
* A default destructor if you do't define one
* A copy constructor if you don't define one
* An assignment operator if you don't define one
* An address operator if you don't define one

if you want to avoid the problem, you should overload these special member functions

