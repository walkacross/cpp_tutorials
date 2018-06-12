# pointer in cpp
(1) how to get the memory storage address of an object(or variable): &object_name

(2) what happens if the value of an object is a memory address?

## the essence of pointer
~~~
int updates =6;
int * p_updates;
p_updates = &updates

*p_updates = *p_updates + 1;

what is the value of update?
~~~

~~~
// p_updates is a pointer object whoes value is an address.
// *p_updates is the object whoes address stored in p_update.
// the function of * is extract object.
// we say that p_updates points to type int. we also say that the type for p_updates is pointer-to-int, more concisely int *.
~~~

## symtax form 
incidentally, the use of spaces around the * operator are optional. Traditionally, C programmer have used this form:
~~~
int *ptr;
~~~

this accentuates the idea that the combination *ptr is a type int value. Many C++ programmer, on the other hand, use this form:
~~~
int* ptr;
~~~
this emphasizes the idea that int* is a type, pointer-to-int.
where you put the spaces makes no difference to the compiler. you could even do this:
~~~
int*ptr
~~~

# allocate memory with **new**
memory allocate during compile time vs memory allocate during runtime

assign the address of a variable to a pointer during compile time
~~~
int higgens;
int * pt = &higgens;
~~~

create unnamed runtime storage for a type int value and accessing the value with a pointer.
~~~
int * pn = new int
~~~
in both cases(pt,pn), you assign the address of an int to a pointer. In the first case, you can also access the int by name: higgens. in the second case, yout only access is via the pointer. that raise a question: Because the momory to which pn points lacks a name, what do you call it? we say that pn points to a data object. the term "data object" is more general than the term "variable" because it means any block of memory allocated for a data item.

the pointer method for handling data objects may seem more awkward at first, but it offers greater control over how your rogram manages memory.

the general form for obtaining and assigning memory for a single data object, which can be a structure as well as a fundamental type. is this:
~~~
typeName * pointer_name = new typeName;
~~~

the parogram in use_new.cpp uses *new* to allocate memory for the type int and type double data object. this occurs while the programming is running rather than compile time. the pointers pt and pd point to these two data object. **without them(pointer) in this case, you cannot access those memory locations. with them, you can use *pt and *pd just as you would use variables.** you assign values to *pt and *pd to assign values to the new data objects. Similarly, you print *pt and *pd to play thoes values.

# free memory with *delete*
the other half of memory-management package is the *delete* operator, which enables you to return memory to the memory pool when you are finished with it.
~~~
int * ps = new int;    // allocate memory with new
...                    // use the memory
delete ps;             // free memory with delete when done
~~~
**this remove the momory to which ps points; it doesn't remove the pointer ps itself, you can reuse ps, for example, to point to another new allocation**

you should always balance a use of new with a use of delete, otherwise, you can wind up with a **memory leak** -- that is, memory that has been allocated bu can no longer be used. if a memory leak grows too large, it can bring a program seeking more momory to a halt.

~~~
you should not attempt to free a block of memory that you have previously freed.
you cannot use delete to free memory created by declaring ordinary variables.
int * ps = new int;  //ok
delete ps;           //ok
delete ps;           // not ok
int jugs = 5;        // ok
int * pi = &jugs;    // ok
delete pi;           // not allowed, memory not allocated by new

conclusion: you should use delete only to free memory allocated with new. however, it's afe to apply delete to a null pointer.
~~~

# using *new* to create dynamic data object
suppose, you are writing a program that might ot might not need an array, depending on information given to the program while it is running. 

if you create an array by declaring it, the space is allocated when the program is compiled. whether or not the program finally uses the array, the array is there, using up memory. Allocating the array during compile time is called *static binding*, meaning that the array is built in to the program at compile time.

but with *new*, you can create an array during runtime if you need it and skip creating the array if you don't need it. Or you can select an array size after the program is running. this is called **dynamic binding**. meaning that the array is created while the program is runing. such an array is called dynamic array.

with static binding, you must specify the aray size when you write the program. with dynamic binding, the program can decide on an array size while the program runs.

~~~
int * psome = new int [10];   
// get a block of 10 int, but the new operator returns the address of the **first** element of the block of 10 int values.

delete [] psome;              // free a dynamic array
~~~
In short, you should observe these rules when you use new and delete:
~~~
Don't use delete to free memory that new didn't allocate.
Don't use delete to free the same block of memory twice in sucession.
use delete [] if you used new [] to allocate an array.
use delete (n brackets) if you used new to allocated a single entity.
it's safe to apply delete to the null pointer(nothing happens).
~~~

## using a dynamic array
you can using psome[0] instead of *psome for the first element, psome[1] for the second slement, and so on. the reason you can do this it that C and C++ handle arrays internally by using pointers anyway.


# pointer, array and pointer arithmetic
the near equlivalence of pointers and array names stems from pointer arithmetic and how C++ handles array internally.
