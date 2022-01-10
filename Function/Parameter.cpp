//Parameter Passing Methods

//1.Call by Value
#include<iostream>
using namespace std;
//Call by address 
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int a,b;
    a=10;
    b=5;
    cout<<a<<endl<<b<<endl;
    swap(&a,&b);
    cout<<a<<endl<<b;
    return 0;
}