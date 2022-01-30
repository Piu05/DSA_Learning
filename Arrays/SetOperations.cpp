#include<iostream>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};
//Union of sorted arrays
struct Array* Union(Array *A1, Array *A2 )
{
    int i,j,k;
    i=j=k=0;
    struct Array *A3=new Array[sizeof(struct Array)];
    while(i<A1->length && j<A2->length)
    {
        if(A1->A[i]<A2->A[j])
            A3->A[k++]=A1->A[i++];
        else if(A1->A[i]>A2->A[j])
            A3->A[k++]=A2->A[j++];
        else
        {
            A3->A[k++]=A1->A[i++];
            j++;
        }
    }
    for(;i<A1->length;i++)
        A3->A[k++]=A1->A[i];
    for(;j<A2->length;j++)
        A3->A[k++]=A2->A[j];
    A3->length=k;
    A3->size=A1->size+A2->size;
    return A3;
}
//Intersection of two sorted arrays
struct Array* Intersection(Array *A1, Array *A2 )
{
    int i,j,k;
    i=j=k=0;
    struct Array *A3=new Array[sizeof(struct Array)];
    while(i<A1->length && j<A2->length)
    {
        if(A1->A[i]<A2->A[j])
            i++;
        else if(A1->A[i]>A2->A[j])
            j++;
        else
        {
            A3->A[k++]=A1->A[i++];
            j++;
        }
    }
    A3->length=k;
    A3->size=A1->size+A2->size;
    return A3;
}
//Difference of two sorted arrays
struct Array* Difference(Array *A1, Array *A2 )
{
    int i,j,k;
    i=j=k=0;
    struct Array *A3=new Array[sizeof(struct Array)];
    while(i<A1->length && j<A2->length)
    {
        if(A1->A[i]<A2->A[j])
            A3->A[k++]=A1->A[i++];
        else if(A1->A[i]>A2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for(;i<A1->length;i++)
        A3->A[k++]=A1->A[i];
    A3->length=k;
    A3->size=A1->size+A2->size;
    return A3;
}
void display(Array arr)
{
    cout<<"elements are: ";
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}
int main()
{
    Array A1={{2,4,6,8,10,11,12},10,7};
    Array A2={{1,2,5,7,10},10,5};
    Array *A3;
    A3=Union(&A1,&A2);
    cout<<"\nAfter union ";
    display(*A3);
    A3=Intersection(&A1,&A2);
    cout<<"\nAfter intersection ";
    display(*A3);
    A3=Difference(&A1,&A2);
    cout<<"\nAfter difference ";
    display(*A3);
    cout<<endl<<endl;
    return 0;
}

/*
NOTE
For a c++ program you can change struct into class and modify accordingly
You can also use template class for a changable data type
*/