//Recursion practice topics
/*
Menu driven program for:
1.Sum of n natural number
2.Factorial of a number
*/
#include<iostream>
using namespace std;
int sum(int n)
{
    if(n==0)
        return 0;
    else
        return sum(n-1)+n;
}
int factorial(int n)
{
    if(n==0)
        return 1;
    return n*factorial(n-1);
}
int main()
{
    int x,choice;
    cout<<"*****MENU*****\n1.Sum of n numbers\n2.Factorial of a number";
    cout<<"\nEnter choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1: cout<<"Enter a number: ";
                cin>>x;
                cout<<"Sum of "<<x<<" numbers :"<<sum(x);
                break;
        case 2: cout<<"Enter a number: ";
                cin>>x;
                cout<<"Factorial of "<<x<<" is :"<<factorial(x);
                break;
        default:cout<<"Wrong choice!!";
                break;
    }
    return 0;
}

//Power using recursion
//Method 1
int pow1(int m,int n)
{
    if(n==0)
        return 1;
    else
        return pow1(m,n-1)*m;
}
//Method 2
int pow2(int m,int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return pow2(m*m,n/2);
    else
        return m*pow2(m*m,(n-1)/2);
}
int main()
{
    int a,b;
    cout<<"Enter 2 numbers for a^b respectively- ";
    cin>>a>>b;
    cout<<"Result is: "<<pow2(a,b);
    return 0;
}

//Fibonacci Series
int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return fib(n-2)+fib(n-1);
}
int main()
{
    int x;
    cout<<"Enter which term of fibonacci series you want: ";
    cin>>x;
    cout<<"The "<<x<<"th term is: "<<fib(x);
    return 0;
}