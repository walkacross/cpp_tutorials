# three ways of managing memory for data object in c++

## 1 automatic storage
ordinary variables defined inside a function use *automatic storage* and are called automatic variables. these terms mean that the variable come into existence automatically when the code block containing them is invoked, and they expire(be freed) when the function terminates.

automatic variables typically are stored on a *stack*. this means that when program execution enters a block of code, it's variabes are added consecutively to the stack in memory and then are freed in reverse order when execution leaves the block.(this s called a last_in, first_out, or LIFO, process.) so the stack grouws and shrinks as execution proceeds.

## 2 static storage
static storage is storage that exists throughout the execution of an entire program. these are two ways to make a variable static. one is define it externally, outside a function. the other is to use the keyword static when declaring a variable:
~~~
static double fee = 56.50;
~~~

the main point you should note now about automatic and static storage is that these method *rigidly* define the lifetime of a variable. Either the variable exists for the entire duration of a program (a static variable) or it exists only while a particular code block is being executed (an automatic variable).

## 3 dynamic storage
the *new* and *delete* operators provide a more flexible apporach than automatic and static variables. they manage a pool of memory, which c++ refers to as the **free store or heap**. this pool is separated from the memory used for static and automatic variables. as examples show, new and delete enable you to allocated memory in one function and free it in another. thus the lifetime of the data object is not tied arbitrarily to the life of the program or the life of a function. using new and delete together gives you much more control over how a program uses memory than does using ordinay variables.


# stack, heaps, and memory leaks
what happens if you don't call delete after creating a variable on the free store(or heap) with the new operator?

> the variable or construct dynamically allocated on the free store continues to persist if *delete* is not called, even though the memory that contains the pointer has been freed due to **rules of scope and object lifetime**. in essence, you have no way to access the construct on the free store because the pointer tothe memory that contains it is gone. you have now create **memory leak**

memory that has been leaked remains unusable theough the life on the program; it's been allocated but can't be deallocated.

> in extreme case(though not uncommon), momory leaks can be so serve that they use up all the memory available to the application, cause it to crash with an out-of-memory error. in addition, these leaks may negatively affect some operating systems or other applications running in the same memory space. causing them, in turn, to fail.
