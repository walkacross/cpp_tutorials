<center># the String class and Standard Template Library</center>

# 1 the String class
## 1.1 8 constructors in String class
~~~
constructors                         description

# ctor 1
string(const char * s)          initializes a string object to the NBDT pointed to by s.

# ctor 2
string(size_type n, char c)     create a string object with n elements, each initialized to the charactoer c.

# ctor 3
string(const string & str)      initialized a string object to the string object str(copy constructor).

# ctor 4 
string()                        create a default string object of 0 size.(default constructor).

# ctor 5
string(const char * s, size_type n)   initilizes a string object tothe NBTS pointed to by s and continues for n characters.

# ctor 6
template<class Iter>
string(Iter begin, Iter end)     the range includeds begin and is up to but not including end.

# ctor 7
string(const string & str, size_typ pos, size_type n = npos)

# ctor 8
string(initilizer_list<char> il)   in c++ 11, this make list-initialization syntax possble,e.t. string piano_mam = {'L','i','s','z','t'}
~~~

## 1.2  the overloaded operator
## 1.3  some useful in-built methods in String class
~~~
string.length()
string.size()
string.capacity()

string.find()
string.find_first_of('hark')
~~~

# 2 Smart Pointer Template Class
A **smart pointer** is a class object that acts like a pointer but has additional features.

# 3 the *vector* template class

## 3.1 how to define a vector class object
vector is one kind of containers in c++.
~~~
vector<int> rating(5);     // a vector of 5 ints

int n;
cin > n;
vector<double> scores(n);   // a vector of n doubles
~~~

## 3.2 how to access and iterate the element in vector

~~~
# access
rating[2]
~~~

~~~
#iterate   ->  introduce the iterator notation
vector<double>::iterator pd;   // pd is an iterator

vector<double> scores;
pd = scores.bengin();   // have pd point to the first element
*pd = 22.3;             // dereference pd and assign value to first element
pd++;;                  // make pd point to the next element, like pointer behavior
~~~

## 3.3 memer function in *vector*
append an element
~~~
double temp = 22.1
scores.push_back(temp)
~~~

remove element in vector
~~~
scores.erase(scores.begin(), scores.begin()+2)
~~~

insert element
~~~
vector<int> old_v;
vector<int> new_v;
old_v.insert(old_v.bengin(), new_v.begin()+1, new_v.end());
~~~

## 3.4 nonmember functions in STL to process unified containers
~~~
for_each(books,bengin(), books.end(), ShowReview);   //like map functions in python

random_shuffle(books.bengin(), books.end());


sort(coolstuff.begin(). coolstuff.end());
~~~

# 4 Generic Programming
*vector* is an example in STL, STL is an example of *generic programming*.

Object-oritned programming concentrated on the data aspect of programming, where as generic programming concentrates on algorithms. the main things the two approches have in common are abstraction and the createing of reusable code, but the philophies are quite different.

A goal of generic programming is to write code that is independent of data types. Templates are the C++ tools for createing generic programs. another tools is the iterator. in short:

Just as the templates make algorithm independent of the type of data **store**, iterator make the algorithms indepent of the type of container used. SO They are an essential component of the STL's generic approch.

# 4.1 why and how iterator works
how to iterate a container in a unified way?
the answer create a abstract base class that define the rules to following.

~~~
class IteratorBase
{
public:
    IteratorBase(){}
    virtual ~IteratorBase(){}
    virtual double * begin() const = 0; //pure virtual function, get the first element address
    virtual double * end() const  = 0;  //get the last element in a container
    virtual IteratorBase& operator++ () =0; // for ++it
    virtual IteratorBase operator++() = 0;  // for it++
}
~~~
the STL follows the approch just outlined.
First, each constainer class defines an its own itertor type approciate to the class. for one class, the iterator might be a pointer; for another, it might be an object.

next, Each container class will have begin() and end() methods that return iterators to the first element in a container and to the past-the-end position.

besides. each container class will have the ++ operation take an iterator from the first element to past-the-end, visiting every container element en route.

the STL defines five kinds of iterators:
~~~
**InputIterator**    read-only to the element in container
**OutputIterator**   write-only to the element like cout
**ForwardIterator**  go forward throuth a conatainer only one element at a time
**BidirectionIterator**  traverse a container in both direction
**RandomAccessIterator**   have the ability to jump directly to an arbitrary element of a container
~~~

for example the find() prototype looks like this
~~~
template<class InputIterator, class T>
InputIterator find(InputIterator first, InputItertor last, const T& value)
~~~

# Function Objects (a.k.a Functors)

function object, also known as functor, is any object that can be used with () in the manner of a function. this includes normal function names, pointers to functions, and class object for which the () operator is overloaded.

for example
~~~
class Linear
{
private:
    double slope;
    double y0;

public:
    Linear(double s1_ = 1, double y_ = 0) : slope(s1_), y0(y_) {}
    double operator()(double x) {return y0 + slope * x;}
};
~~~
the overloaded () operator then allows you to use Linear objects like functions:
~~~
Linear f1;
Linear f2(2.5, 10.0);
double y1 = f1(12.5);     // right-hand side is f1.operator()(12.5)
double y2 = f2(0.4)
~~~
