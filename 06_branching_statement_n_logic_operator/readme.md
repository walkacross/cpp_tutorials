# 1introduction

## if statement
~~~
statement 1
if (test_expr)
    statement2
statement3
~~~

## if else statement
~~~
statement1
if (test_expr)
    statement2
else
    statement3
statement4
~~~

## if else if statement
~~~
statement0
if (test_expr1)
    statement1
else if (test_expr2)
    statement2
else
    statement3
statement4
~~~


## switch
~~~
switch (expression)
{
    case label1 : statement1
    case label2 : statement2
    ...
    default     : statement
}
~~~

# logical expression

## 1 syntax
* logical OR, written ||
* logical AND, written &&
* logical NOT, written !

~~~
5 == 5 || 5 == 9  //true cuz first expression is true
5 >8 || 5 < 2     //false, cuz both are false


5 == 5 && 4 == 4 // true, cuz both are true
5 >3 && 5 >10    // false, cuz the second are false
~~~

## 2 precedence
* relation operators have a higher precedence than logical operators
~~~
x >5 && x < 10 will be compiled (x>5) && (x<10)
~~~

* the logical AND operator has a higher precedence than the logical OR
~~~
age > 30 && age < 45 || weight > 300

means the following:
(age > 30 && age < 45) || weight > 300
~~~

## 3 conditional operator(?:)
alternative representations for if-else
syntax:
~~~
expression1 ? expression2 : expression3
~~~
if expression1 is true, then the value of the whole conditional expression is the value of expression2. otherwise, the value of the whole expression is the value of expression3.

~~~
5 > 3 ? 10:12  // 5>3 is true, so expression value is 10
3==9 ? 25 : 18  // 3==9 is false, so expression value is 18
~~~

# the creak and continue statement
the break and continue statements enable a program to skip over parts of the code. you can us the break statement in any of the loops. it cause program execution to pass to the next statement following the loop.

the continue statement is used in loops and cause a program to skip the rest of the body of the loop and then start a new loop cycle.
