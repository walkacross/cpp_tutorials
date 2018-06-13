<center>Working with classes</center>

# Operator Overloading
overloaded operators can oftern make code look more natural. for example

add two array
~~~
for (int i = 0; i<20; i++)
    evening[i] = sam[i] + janet[i];  //add element by element
~~~
in c++, you can define a class that represents arrays and that overloads the + operator so that you can do this:
~~~
evening = sam + hanet;    //add two array objects
~~~

## time on our hands: developing an operator overloading example
see example 11_1

rename the Time.Sum() to Time.operator+(), then
~~~
total = coding.oprator+(fixing);  //function notation
~~~

you can also use this
~~~
total = coding + fixing;      // operator notation
~~~

# introducing Friends
a friend function to a class is a nonmember function that has the same access rights as a member function.

Friends come in three varieties:
* Friend functions
* Friend classes
* Friend member functions

# auromatic conversion and type cast for classes
skip
