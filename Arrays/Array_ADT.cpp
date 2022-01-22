//Array Abstract Data Type
/*
Data-
1.Array space
2.Size
3.Length(No. of elements)

Operations-
1.Display()
2.Add(x)/Append(x)
3.Insert(x)
4.Delete(index)
5.Search(x)
6.Get(index)
7.Set(index,x)
8.Min()/Max()
9.Reverse()
10.Shift()/Rotate()
*/

#include<iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};
//For append
void append(Array *arr,int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}
//For display 
void display(Array arr)
{
    cout<<"Elements are: ";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}
int main()
{
    Array arr;
    int n,value;
    cout<<"Enter no. of elements:";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr.A[i];
    }
    arr.length=n;
    display(arr);
    cout<<"\nEnter value to append: ";
    cin>>value;
    append(&arr,value);
    cout<<"After appending ";
    display(arr);
    return 0;
}