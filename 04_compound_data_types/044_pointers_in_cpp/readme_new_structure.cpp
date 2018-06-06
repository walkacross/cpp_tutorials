# using new to create dynamic structure
*dynamic* means the memory is allocated during runtime, not at compile time.

~~~
struct things
{
    int good;
    int bad;
}

thing grubnose = {3, 453};
thing * pt = &grubnose;
~~~

how to access thins instance's member
for instance
~~~
grubnose.good
grubnose.bad
~~~

for pointer point to a structure, you have two method to access it member
method1:
~~~
(*pt).good
(*pt).bad
~~~

method2:
~~~
pt->good
pt->bad
~~~
