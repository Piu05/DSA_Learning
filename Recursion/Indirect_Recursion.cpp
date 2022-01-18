//Indirect Recursion
//Function calls itself in another function 
#include<iostream>
using namespace std;
void funA(int);
void funB(int);
void funA(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        funB(n-1);
    }
}
void funB(int m)
{
    if(m>1)
    {
        cout<<m<<" ";
        funA(m/2);
    }
}
int main()
{
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    funA(x);
    return 0; 
}
