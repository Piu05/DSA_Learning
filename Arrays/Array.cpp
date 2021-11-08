//Array Basics
//Size Of Array
#include<iostream>
using namespace std;
int main()
{
    int A[5]={12,15,25};
    cout<<sizeof(A)<<endl;
    cout<<A[1]<<endl;
    cout<<A[4]<<endl;

//Printing whole array
    for(int i=0;i<5;i++)
    {
        cout<<A[i]<<endl;
    }

//Variable sized array
    int n;
    cout<<"Enter size:";
    cin>>n;
    int B[n];
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    cout<<"Array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<B[i]<<" ";
    }
    return 0;
}