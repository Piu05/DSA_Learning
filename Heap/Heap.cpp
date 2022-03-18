/*
Binary Heap:
-It must be a complete binary tree
-Every node should have element greater or equal to all its descendants then it is max. heap
-Every node should have element smaller or equal to all its descendants then it is min. heap
*/
#include<iostream>
using namespace std;
//Max Heap
void Insert(int A[],int n)
{
    int temp,i=n;
    temp=A[i];
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
int Delete(int a[],int n)
{
    int x,i,j,temp,val;
    x=a[n];
    val=a[1];
    a[1]=a[n];
    a[n]=val;
    i=1,j=2*i;
    while(j<n-1)
    {
        if(a[j+1]>a[j])
            j=j+1;
        if(a[i]<a[j])
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
    }
    return val;
}
void Display(int A[])
{
    int i=1;
    while(i<8)
    {
        cout<<A[i]<<" ";
        i++;
    }
    cout<<endl;
}
int main()
{
    int H[]={0,10,20,30,25,5,40,35};      //Create Heap
    for(int i=2;i<8;i++)
    {
        Insert(H,i);
    }
    Display(H);
    for(int i=7;i>1;i--)                //Heap Sort
        Delete(H,i);
    Display(H);
    return 0;
}

/*
NOTE: 
-When elements are inserted in a heap and then deleted one by one by storing deleted elements
in the last place then the result is a sorted list.
-Binary Heap As Priority Queue
If we have to delete higher priority element from the list then we can create a max/min heap and then
delete elements from max/min heap to reduce time
*/  