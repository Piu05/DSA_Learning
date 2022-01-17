/* Recursion practice topics
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