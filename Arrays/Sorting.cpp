#include<iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};
//Insert an element in sorted array
void Insert(Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
//Check whether list is sorted
void isSorted(Array arr)
{
    for(int i=0;i<(arr.length-1);i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {    
            cout<<"Array is not sorted";
            exit(0);
        }
    }
    cout<<"Array is sorted";
}
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
//Sort array by having all negative values on left and positive on right
void Rearrange(Array *arr)
{
    int i=0;
    int j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)
            i++;
        while(arr->A[j]>0)
            j--;
        if(i<j)
            swap(&arr->A[i],&arr->A[j]);
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
    Array arr={{2,-3,5,-7,9},10,5};
    Insert(&arr,8);
    display(arr);
    isSorted(arr);
    Rearrange(&arr);
    display(arr);
    return 0;

}