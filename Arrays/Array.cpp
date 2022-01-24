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

//2D Array Declaration
//Method 1
    int Q[3][4];            //Created in stack memory

//Method 2
    int *P[3];              //Created in stack memory
    P[0]=new int[4];        //Created in heap memory
    P[1]=new int[4];        //Created in heap memory
    P[2]=new int[4];        //Created in heap memory

//Method 3
    int **R;                //Created in stack memory
    R=new int*[3];          //Created in heap memory
    R[0]=new int[4];        //Created in heap memory
    R[1]=new int[4];        //Created in heap memory
    R[2]=new int[4];        //Created in heap memory
    return 0;
}
/*
//Address of array in compiler
Address(A[i])=B+(i*w)             where B=Base address, i=index, w=size of data type
Address(A[i][j])=B+(i*n+j)*w      where n=column size [Row major formula]
Address(A[i][j])=B=(j*m+i)*w      where m=row size    [Column major formula]

For Type A[d1][d2][d3].....[dn]
Address(A[i1][i2]...[in])=B+{summation(p=1->n){ip*[product(q=p+1->n)dq]}}*w     [Row Major]
Time Complexity= O(n^2)     [Row Major]
*/