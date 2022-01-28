#include<iostream>
using namespace std;
//Find one missing number from consecutive natural numbers
int MissingElement(int A[],int n)
{
    int num=-1,sum=0;
    for(int i=0;i<10;i++)
    {
        sum+= A[i];
    }
    int s=(n*(n+1))/2;
    if(s!=sum) 
        num=s-sum;
    return num;
}
//Find multiple missing numbers from series
void MissingElements(int A[], int l, int n)
{
    int diff= l-0;
    for(int i=0;i<n;i++)
    {
        if(A[i]-i!=diff)
        {
            while(diff<A[i]-i)
            {
            cout<<"\nMissing no. is "<<i+diff;
            diff++;
            }
        }
    }
}
//Method 2 for multiple elements missing (Using hash table)
void MissingElements2(int A[], int l, int h, int n)
{
    int A2[h];
    int p=0;
    for(int i=0;i<h;i++)
    {
        A2[i]=0;
    }   
    for(int i=0;i<n;i++)     
    {   
        A2[A[i]]++;
    }
    for(int i=1;i<h;i++)
    {
        if(A2[i]==0)
            cout<<"\nMissing no. is "<<i;
    }
}
//Finding duplicate elements in sorted array
void Duplicate(int A[],int n)
{
    int lastDuplicate=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==A[i+1] && A[i]!=lastDuplicate)
        {
            lastDuplicate=A[i];
            cout<<"\nDuplicate no. is "<<lastDuplicate;
        }
        if(A[i]==A[i+1])
        {
            int j=i+1;
            while(A[j]==A[i])j++;
            cout<<" and it is repeating "<<j-i<<" times";
            i=j-1;
        }
    }
}
//Method 2 for duplicate elements (for both sorted and unsorted array)
void Duplicate2(int A[],int h,int n)
{
    int A2[h];
    int p=0;
    for(int i=0;i<h;i++)
    {
        A2[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        A2[A[i]]++;
    }
    for(int i=0;i<h;i++)
    {
        if(A2[i]>1)
            cout<<"\n"<<i<<" is repeated "<<A2[i]<<" times";
    }
}
//Finding pair of elements with sum k
void FindSum(int A[],int sum,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i]+A[j]==sum)
                cout<<"\nPair with sum "<<sum<<" is "<<A[i]<<","<<A[j];
        }
    }
}
//Finding pair of elements with sum k using hash table
void FindSum2(int A[],int h,int n,int sum)
{
    int A2[h];
    for(int i=0;i<h;i++)
    {
        A2[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(A2[sum-A[i]]!=0 && sum-A[i]>0)
            cout<<"\nPair with sum "<<sum<<" is:"<<A[i]<<" "<<sum-A[i];
        A2[A[i]]++;
    }
}
//Find pair of elements with sum k in sorted array
void FindSumS(int A[],int sum, int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(A[i]+A[j]==sum)
        {
            cout<<"\nPair is "<<A[i]<<","<<A[j];
            i++;
            j--;
        }
        else if(A[i]+A[j]<sum)
            i++;
        else
            j--;
    }
}
int main()
{
    int A[11]={1,2,3,4,5,6,8,9,10,11,12};
    int B[11]={6,7,8,9,11,12,13,14,16,17,18};
    int C[10]={3,7,4,9,12,6,1,11,2,10};    
    int D[10]={3,4,8,8,12,13,15,15,15,18};
    int E[10]={8,12,13,15,3,4,8,15,15,18};
    int F[10]={6,3,8,10,16,7,5,2,9,14};
    int G[10]={1,3,4,5,6,7,8,9,10,12};
    //for single element missing 
    int a=MissingElement(A,11);
    if(a==-1)
        cout<<"No missing no. in series";
    else 
        cout<<"The missing no. is => "<<a;
    //Method 1 for multiple elements missing
    MissingElements(B,6,11);
    //Method 2 using hash table
    MissingElements2(C,1,12,10);
    //Duplicate
    Duplicate(D,10);
    //Duplicate 2 using hash table 
    Duplicate2(E,18,10);
    //Find pair of elements with sum k
    FindSum(F,10,10);
    //Find pair of elements with sum k using hash table
    FindSum2(F,16,10,10);
    //Find pair of elements with sum k in sorted array
    FindSumS(G,10,10);
    return 0;
}