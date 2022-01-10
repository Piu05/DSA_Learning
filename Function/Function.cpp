//Theory
//functions are used to perform a specific tasks separately instead of mpnolithic programming
//it is called modular(or procedural) programming
#include<iostream>
using namespace std;
int add(int a,int b)            //Declaration and definition
{
    int c;
    c=a+b;
    return c;
}
int main()
{
    int x,y,z;
    cout<<"Enter two values"<<endl;
    cin>>x>>y;
    z=add(x,y);                 //Function calling
    cout<<"The sum is: "<<z;
    return 0;
}