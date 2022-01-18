//Nested Recursion (Recursion inside recursion)
//When the recursive statement parameter is a recursion call as well
#include<iostream>
using namespace std;
int fun(int n)
{
    if(n>100)
        return n-10;
    return fun(fun(n+11));
}
int main()
{
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    cout<<fun(x);
}