#include<iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int linearSearch(Array *arr, int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {   
            swap(&arr->A[i],&arr->A[i-1]);          //Improvisation
            return i;
        }
    }
    return -1;
}
void display(Array arr)
{
    cout<<"Elements are: ";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}
int main()
{
    int key,val;
    struct Array arr={{2,3,4,5,6,7,8},10,7};
    cout<<"Enter the number you want to search: ";
    cin>>key;
    val=linearSearch(&arr,key);
    if(val==-1)
        cout<<"Number not found";
    else
        cout<<"Number found at index "<<val;
    display(arr);
    return 0;
}