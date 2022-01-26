#include<iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};
struct Array* merge(Array *A1,Array *A2)
{
    int i=0,j=0,k=0;
    Array *A3=new Array[sizeof(struct Array)];
    while(i<A1->length && j<A2->length)
    {
        if(A1->A[i]<A2->A[j])
            A3->A[k++]=A1->A[i++];
        else
            A3->A[k++]=A2->A[j++];
    }
    for(;i<A1->length;i++)
        A3->A[k++]=A1->A[i];
    for(;j<A2->length;j++)
        A3->A[k++]=A2->A[j];
    A3->length=A1->length+A2->length;
    A3->size=A1->size+A2->size;
    return A3;
}
void display(Array arr)
{
    cout<<"Elements are: ";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}
int main()
{
    Array A1={{2,4,6,8,10,11,12},10,7};
    Array A2={{1,3,5,7,9},10,5};
    Array *A3;
    A3=merge(&A1,&A2);
    display(*A3);
    return 0;

}