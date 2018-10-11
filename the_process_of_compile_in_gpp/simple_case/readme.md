# 编译的四个具体流程
预处理 > 编译 > 汇编 > 链接

1预处理: 将所有#include的文件和宏定义替换成其真正的内容，预处理后仍然得到的是文本代码;
~~~
g++ hello_fn -o hello_fn.i -E
g++ main.cpp -o main.i -E
~~~
查看文本代码
~~~
cat main.i
~~~

2编译:将预处理之后的程序转换为特定汇编代码的过程，是将源文件转换为二进制可执行文件的第一步操作。
~~~
g++ hello.i -o hello_fn.s -S
g++ main.i -o main.s -S
~~~

3汇编: 将编译得到的汇编代码转化为机器码，生成二进制目标文件(object file).
~~~
g++ hello_fn.s -o hello_fn.o -c
g++ main.s -o main.o -c
~~~

4链接: 将1多个目标文件 2以及所需要的库文件（.a/.so）链接成最终的可执行文件
~~~
g++ main.o hello_fn.o -o main.exe
~~~

运行可执行文件
~~~
./main.exe
~~~


# 编译的集成命令
~~~
g++ main.cpp hello_fn.cpp -o main.exe
~~~

~~~
./main.exe
~~~

