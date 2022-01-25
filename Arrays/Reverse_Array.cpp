#include<iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
//Method 1
void Reverse1(Array *arr)
{
    int i,j;
    int *B;
    B=new int[arr->length];
    for(i=(arr->length-1),j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
}
//Method 2
void Reverse2(Array *arr)
{
    int i,j,temp;
    for(i=0,j=(arr->length-1);i<j;i++,j--)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}
void display(Array arr)
{
    cout<<"Elements are: ";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}
int main()
{
    Array arr = {{1,2,3,4,5,6},10,6};
    Reverse2(&arr);
    display(arr);
    return 0;
}