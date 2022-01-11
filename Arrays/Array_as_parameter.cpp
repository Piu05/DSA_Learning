#include<iostream>
using namespace std;
void fun(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
}
int main()
{
    int A[5]={2,4,6,8,10};
    fun(A,5);
}
//Example
void fun(int A[],int n)
{
    cout<<sizeof(A)/sizeof(int)<<endl;      //Here sizeof(A) will be size of pointer not of array
    A[0]=12;
    cout<<"After Changing: ";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
}
int main()
{
    int A[]={2,4,6,8,10};
    int n=5;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    fun(A,n);
}