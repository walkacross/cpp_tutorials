# 1 link the external library at link-time
~~~
g++ main.cpp hello_fn.cpp -o test.exe -I ./external_lib -L ./external_lib -lapi
~~~

-I: specify the search path of include file of external library
-L: specify the search path of library file(.a/.so) of external library
-l: spefify the name of library file

# 2 specify the search path of external library during the run-time
##method1: specify the LD_LIBRARY_PATH
~~~
export LD_LIBRARY_PATH = $LD_LIBRARY_PATH:/path/to/lib
./test.exe
~~~

##method2: specify the run-time search path at link-time by rpath, this will record the search path to the compiled file
~~~
g++ main.cpp hello_fn.cpp -o test.exe -I ./external_lib -L ./external
_lib -lapi -Wl,-rpath=./external_lib
./test.exe     //directly
~~~
