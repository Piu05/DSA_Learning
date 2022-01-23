#include<iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
int linearSearch(Array arr, int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}
int main()
{
    int key,val;
    struct Array arr={{2,3,4,5,6,7,8},10,7};
    cout<<"Enter the number you want to search: ";
    cin>>key;
    val=linearSearch(arr,key);
    if(val==-1)
        cout<<"Number not found";
    else
        cout<<"Number found at index "<<val;
    return 0;
}