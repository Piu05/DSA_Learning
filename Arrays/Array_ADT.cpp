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
    if((arr->length)<(arr->size))
    {
        arr->A[arr->length]=x;
        arr->length++;
    }
}
//For display 
void display(Array arr)
{
    cout<<"Elements are: ";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}
//For insert
void insert(Array *arr,int index,int x)
{
    if(index>=0 && index<=(arr->length))
    {
        for(int i=arr->length;i>index;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}
//For delete
void Delete(Array *arr,int index)
{
    int x;
    x=arr->A[index];
    for(int i=index;i<arr->length;i++)
        arr->A[i]=arr->A[i+1];
    arr->length--;
}
int main()
{
    Array arr;
    int n,index,value1,value2;
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
    cin>>value1;
    append(&arr,value1);
    cout<<"After appending ";
    display(arr);
    cout<<"\nEnter index and value to insert: ";
    cin>>index>>value2;
    insert(&arr,index,value2);
    cout<<"After inserting ";
    display(arr);
    cout<<"\nEnter index to delete: ";
    cin>>index;
    Delete(&arr,index);
    cout<<"After deleting ";
    display(arr);
    return 0;
}