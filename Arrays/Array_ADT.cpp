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
//For getting a value
int Get(Array arr,int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}
//For setting a value
void Set(Array *arr,int index,int x)
{
    if(index>=0 && index<(arr->length))
    arr->A[index]=x;
}
//For finding maximum value
int Max(Array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}
//For finding minimum value
int Min(Array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}
//For sum 
int Sum(Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
        sum+=arr.A[i];
    return sum;
}
//For average
float Avg(Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
        sum+=arr.A[i];
    return sum/arr.length;
}
int main()
{
    Array arr;
    int n,index,value1,value2,a;
    cout<<"Enter no. of elements:";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr.A[i];
    }
    arr.length=n;
    cout<<"*****MENU*****";
    cout<<"1.Append\n2.Insert\n3.Delete\n4.Display\n5.Get\n6.Set\n7.Max\n8.Min\n9.Sum\n10.Average\n11.Exit";
    cout<<"\nEnter your choice: ";
    cin>>a;
    switch(a)
    {
        case 1: cout<<"\nEnter value to append: ";
                cin>>value1;
                append(&arr,value1);
                cout<<"After appending ";
                display(arr);
                break;
        case 2: cout<<"\nEnter index and value to insert: ";
                cin>>index>>value2;
                insert(&arr,index,value2);
                cout<<"After inserting ";
                display(arr);
                break;
        case 3: cout<<"\nEnter index to delete: ";
                cin>>index;
                Delete(&arr,index);
                cout<<"After deleting ";
                display(arr);
                break;
        case 4: display(arr);
                break;
        case 5: cout<<"Enter the index: ";
                cin>>index;
                cout<<Get(arr,index);
                break;
        case 6: cout<<"Enter the index: ";
                cin>>index;
                cout<<"Enter the value: ";
                cin>>value1;
                Set(&arr,index,value1);
                display(arr);
                break;
        case 7: cout<<"Maximum value is: "<<Max(arr);
                break;
        case 8: cout<<"Minimum value is: "<<Min(arr);
                break;
        case 9: cout<<"Sum of array elements is: "<<Sum(arr);
                break;
        case 10:cout<<"Average is: "<<Avg(arr);
                break;
        case 11:exit(0);
        default:"Wrong option";
                break;
    }
    return 0;
}