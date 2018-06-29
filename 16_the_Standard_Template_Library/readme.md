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

