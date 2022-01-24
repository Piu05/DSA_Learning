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

//Fibonacci Series (time- O(2^n))
//Method 1
int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return fib(n-2)+fib(n-1);
}
//Method 2 (using memoization)
int F[10];
int fib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=fib(n-2);
        if(F[n-1]==-1)
            F[n-1]=fib(n-1);
        return F[n-2]+F[n-1];
    }
}
int main()
{
    for(int i=0;i<10;i++)
        F[i]=-1;
    int x;
    cout<<"Enter which term of fibonacci series you want: ";
    cin>>x;
    cout<<"The "<<x<<"th term is: "<<fib(x);
    return 0;
}

//Taylor Series (e^x)
//Method 1
double e(int x,int n)
{
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    else
    {
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}
//Method 2 (Taylor Series using Horner's Rule)
double e(int x,int n)
{
    static double s;
    if(n==0)
    return s;
    s=1+x*s/n;
    return e(x,n-1);
}
//Method 3 (using loops)
double e(int x,int n)
{
    double s=1, num=1, den=1;
    for(int i=0;i<=n;i++)
    {
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}
int main()
{
    int a,b;
    cout<<"Enter power of e: ";
    cin>>a;
    cout<<"Enter no. of terms: ";
    cin>>b;
    cout<<"Value of e^"<<a<<" is: "<<e(a,b);
    return 0;
}

//nCr formula (or combination formula)
//Method 1
int fact(int n)
{
    if(n==0)
        return 1;
    return n*fact(n-1);
}
int C(int n,int r)
{
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(r);
    t3=fact(n-r);
    return t1/(t2*t3);
}
//Method 2 (Pascal's Triangle)
int C(int n,int r)
{
    if(r==0||n==r)
        return 1;
    else
        return C(n-1,r-1)+C(n-1,r);
}
int main()
{
    int n,r;
    cout<<"Enter n and r :";
    cin>>n>>r;
    cout<<"Value of nCr is: "<<C(n,r);
    return 0;
}