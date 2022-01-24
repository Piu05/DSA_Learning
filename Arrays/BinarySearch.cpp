#include<iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
//Using while loop
int BinarySearch(Array arr, int key)
{
    int l=0,mid,h;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr.A[mid]==key)
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
//Using recursion
int RBinarySearch(int a[],int l,int h,int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinarySearch(a,l,mid-1,key);
        else
            return RBinarySearch(a,mid+1,h,key);
    }
    return -1;
}
int main()
{
    int key,val;
    Array arr={{1,2,3,4,5,6,7,8},10,8};
    cout<<"Enter the element you want to search: ";
    cin>>key;
//    val=BinarySearch(arr,key);
    val=RBinarySearch(arr.A,0,arr.length,key);
    if(val==-1)
        cout<<"Element not found";
    else
        cout<<"Element found at index "<<val;
    return 0;
}