//Parameter Passing Methods

//1.Call by Value
#include<iostream>
using namespace std;
void swap(int x,int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int main()
{
    int a,b;
    a=10;
    b=5;
    cout<<a<<endl<<b<<endl;
    swap(a,b);
    cout<<a<<endl<<b; //here value will not change i.e.,a=10 b=5 bcoz actual parameters will not change bcoz of formal parameters
    return 0;
}

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
    cout<<a<<endl<<b;       //Swapping will be done and values will be interchanged
    return 0;
}

//Call by Reference (used in c++, cannot be used often)
void swap(int &x,int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int main()
{
    int a,b;
    a=10;
    b=5;
    cout<<a<<endl<<b<<endl;
    swap(a,b);
    cout<<a<<endl<<b;       //Swapping will be done and values will be interchanged
    return 0;
}