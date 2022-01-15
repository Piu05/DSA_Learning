//Recursion
/*
-A function calling itself is called a recursion.
-It should have a termination statement to stop its infinite loop.
Syntax:
type fun(para)
{
    if(<base condition>)
    {
        ..
        ..
        fun(para);
        ..
    }
}
*/

//Example 1
#include<iostream>
using namespace std;
void fun1(int n)
{
    if(n>0)
    {
        cout<<n<<" ";           //line 1
        fun1(n-1);              //line 2
    }
}
void main()
{
    int x=5;
    fun1(x);    
}
//Output- 5 4 3 2 1

//Example 2
void fun2(int n)
{
    if(n>0)
    {
        fun2(n-1);              //line 3
        cout<<n<<" ";           //line 4
    }
}
void main()
{
    int x=5;
    fun2(x);    
}
//Output- 1 2 3 4 5

//Here the output differs due to just a minor change.
//In 1st example, control first goes to line 1, it prints and then goes to line 2 then recursion occurs
//..and again it prints then again recursion occurs

//In 2nd example, control first goes to line 3, recursion occurs and the printing in on hold, then during recursion
//..same thing happens till the time recurion ends. then now line 4 i.e. printing takes place after the last recursion
//..and goes upward

//That is why the output in both examples are opposite.

/*
So in the syntax if :
{
line 1;
recursion line; (eg. fun1(n-1))
line 2;
}
then line 1 will be executed while calling and line 2 will be called upon returning
*/