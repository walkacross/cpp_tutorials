# how to write a c++ library


# 1 library structure
-src : general source files
-include : header files that expose the public interface and are to be install
-lib : contain static and shared object files
-bin : executable application based on library
-ext : third party library
-test : test code

# 2 elementary knowledge
http://www.network-theory.co.uk/docs/gccintro/gccintro_25.html

a library is a collection of precompiled object files which can be linked into program.

## 2.1 static library
Libraries are typically stored in special archive files with the extension '.a', refered to as static libraries. they are created from object files with a separate tool *ar* and used by the linker to resolve references to functions at compile-time.

step 1: generate static library
~~~
#in -lib
g++ -c -I /path/to/mylib/include/ /path/to/myapi/src/api.cpp
ar -r libapi.a api.o
~~~

step 2: link at compile-time
~~~
g++ main.cpp -I /path/to/myapi/include -L /path/to/myapi/lib -lapi -static -o exec_static
~~~

## shared libraries
External librarues are usually provided in two forms: static libraries and shared libraries. static libraries are the '.a' files. when a program is linked against a static library, the machine code from the object files for any external function used by the program is copied from the library into the final executable.

Shared libraries are handled with a more advanced form of linking, which makes the executable file smaller. they use the extension '.so', which stands for shared object.

ynamic linking makes executable files smaller and saves disk space, because one copy of a library can be shared between multiple programs. Most operating systems also provide a virtual memory mechanism which allows one copy of a shared library in physical memory to be used by all running programs, saving memory as well as disk space.

Furthermore, shared libraries make it possible to update a library without recompiling the programs which use it (provided the interface to the library does not change).

Because of these advantages gcc compiles programs to use shared libraries by default on most systems, if they are available. Whenever a static library ‘libNAME.a’ would be used for linking with the option -lNAME the compiler first checks for an alternative shared library with the same name and a ‘.so’ extension.

In this case, when the compiler searches for the ‘libgdbm’ library in the link path, it finds the following two files in the directory ‘/opt/gdbm-1.8.3/lib’:

$ cd /opt/gdbm-1.8.3/lib
$ ls libgdbm.*
libgdbm.a  libgdbm.so
Consequently, the ‘libgdbm.so’ shared object file is used in preference to the ‘libgdbm.a’ static library.

However, when the executable file is started its loader function must find the shared library in order to load it into memory. By default the loader searches for shared libraries only in a predefined set of system directories, such as ‘/usr/local/lib’ and ‘/usr/lib’. If the library is not located in one of these directories it must be added to the load path.(10)

The simplest way to set the load path is through the environment variable LD_LIBRARY_PATH. For example, the following commands set the load path to ‘/opt/gdbm-1.8.3/lib’ so that ‘libgdbm.so’ can be found:

$ LD_LIBRARY_PATH=/opt/gdbm-1.8.3/lib
$ export LD_LIBRARY_PATH
$ ./a.out
Storing key-value pair... done.
The executable now runs successfully, prints its message and creates a DBM file called ‘test’ containing the key-value pair ‘testkey’ and ‘testvalue’.

To save typing, the LD_LIBRARY_PATH environment variable can be set automatically for each session using the appropriate login file, such as ‘.bash_profile’ for the GNU Bash shell.

Several shared library directories can be placed in the load path, as a colon separated list DIR1:DIR2:DIR3:...:DIRN. For example, the following command sets the load path to use the ‘lib’ directories under ‘/opt/gdbm-1.8.3’ and ‘/opt/gtk-1.4’:

$ LD_LIBRARY_PATH=/opt/gdbm-1.8.3/lib:/opt/gtk-1.4/lib
$ export LD_LIBRARY_PATH
If the load path contains existing entries, it can be extended using the syntax LD_LIBRARY_PATH=NEWDIRS:$LD_LIBRARY_PATH. For example, the following command adds the directory ‘/opt/gsl-1.5/lib’ to the load path shown above:

$ LD_LIBRARY_PATH=/opt/gsl-1.5/lib:$LD_LIBRARY_PATH
$ echo $LD_LIBRARY_PATH
/opt/gsl-1.5/lib:/opt/gdbm-1.8.3/lib:/opt/gtk-1.4/lib
It is possible for the system administrator to set the LD_LIBRARY_PATH variable for all users, by adding it to a default login script, such as ‘/etc/profile’. On GNU systems, a system-wide path can also be defined in the loader configuration file ‘/etc/ld.so.conf’.

Alternatively, static linking can be forced with the -static option to gcc to avoid the use of shared libraries:

$ gcc -Wall -static -I/opt/gdbm-1.8.3/include/ 
    -L/opt/gdbm-1.8.3/lib/ dbmain.c -lgdbm
This creates an executable linked with the static library ‘libgdbm.a’ which can be run without setting the environment variable LD_LIBRARY_PATH or putting shared libraries in the default directories:

$ ./a.out
Storing key-value pair... done.
As noted earlier, it is also possible to link directly with individual library files by specifying the full path to the library on the command line. For example, the following command will link directly with the static library ‘libgdbm.a’,

$ gcc -Wall -I/opt/gdbm-1.8.3/include 
    dbmain.c /opt/gdbm-1.8.3/lib/libgdbm.a
and the command below will link with the shared library file ‘libgdbm.so’:

$ gcc -Wall -I/opt/gdbm-1.8.3/include 
    dbmain.c /opt/gdbm-1.8.3/lib/libgdbm.so
In the latter case it is still necessary to set the library load path when running the executable.

step 1: generate shared libraries
~~~
#in -lib
g++ -shared -fPIC -o libapi.so -I /path/to/mylib/inlcude/ /path/to/mylib/src/api.cpp
~~~

step 2: compile and link
~~~
g++ main.cpp -I /path/to/myapi/include  -L /path/to/myapi/lib -lapi -o exec_so
~~~

step 3: Although the example program above has been successfully compiled and linked, a final step is needed before being able to load and run the executable file.

method 1: set the search_path to environment temporarily (once)
~~~
export LD_LIBRARY_PATH = $LD_LIBRARY_PATH:/path/to/myapi/lib

./exec_so
~~~

