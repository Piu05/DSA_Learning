#include<iostream>
using namespace std;
int fun(int n)
{
    if(n>0)
        return fun(n-1)+n;  //It will execute upon returning
    return 0;
}
int main()
{
    int x=5;
    cout<<fun(5);
    return 0;
} 
//Output=15

int fun(int n)
{
    static int a=0;         //Static variable declaration
    if(n>0)
    {
        a++;
        return fun(n-1)+a;  //It will execute upon returning
    }
    return 0;
}
int main()
{
    int x=5;
    cout<<fun(5);
    return 0;
}
//Output=25  (since function will recall itself till n=0, a will be incremented to 5 then upon
//            returning a will be added to fun(n-1) i.e. 5 will be added every time till it completes )
