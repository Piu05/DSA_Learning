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
int main()
{
    int A[10]={1,2,3,4,5,6,7,9,10,11};
    int a=MissingElement(A,11);
    if(a==-1)
        cout<<"No missing no. in series";
    else 
        cout<<"The missing no. is => "<<a;
    return 0;
}