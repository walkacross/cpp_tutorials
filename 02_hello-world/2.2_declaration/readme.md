# declaration in cpp
To store an item of information in a computer, you must identify both the storage location and how much memory storage space the information requires. One relatively painless way to do this in C++ is to use a **declaration statement** to indicate the type of storage and **to provide a label for the location**.

for example
~~~
int carrots;
~~~
this declaration statement provide two kinds of information:

(1) the type of memory storage;

(2) a label to attach to that storage which can store an integer: which means you can the program will use the name *carrots* to identify the value stored at that location

# Assignment statements
An assignment statement assignment a value to a storage location. For example
~~~
carrots =  25
~~~
the = symbol is called the assignment operator.

# how to understand this?
## from the perspective of memory storage:
> one memory storage M is an object which has some attributes
>when conduct decaltion statement **int carrots**, the computer will allocate one memory storage M and assign some attribute to it, M.location = #329311 M.lable = carrots M.type = 'int', M.size = 4byte
> when conduct assignment statement **carrots = 25**, this will assignment M.value = 25.

> *carrots* is called Variable. you can call *carrots* which will return the value stored M. and change it value by other assignment statement like *carrots = carrots+3*

## from the varibale perspective:
~~~
1 declaration statement: create a variable object: *carrots* carrots.location = #329311, carrots.label='carrots', carrots.type = int, carrots.size = 4byte

2 assignment statement: carrots.value = 25
~~~
