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

//for array in heap memory use the below syntax (in C++)
    int *p;
    p= new int[5]; //It will allocate memory in heap for 5 units
    p[0]=12;       //Enter values so on 
    delete []p;    //It will deallocate memory if not needed
    
//Increase size of array
    int *p= new int[5];         //Pre-existing small array
    int *q= new int[20];        //New created array
    for(int i=0;i<5;i++)
        q[i]=p[i];
    delete []p;
    p=q;
    q=NULL;
    return 0;
}
