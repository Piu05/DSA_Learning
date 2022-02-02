//Upper Triangular Matrix (M[i,j]=0     if i>j)
#include<iostream>
using namespace std;
class UpperTri
{
    int n;
    int *A;
    public:
    UpperTri(int n)
    {
        this->n=n;
        A=new int[n];
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~UpperTri()
    {
        delete []A;
    }
};
//Row Major Method
void UpperTri::Set(int i,int j,int x)
{
    if(i<=j)
        A[n*(i-1)-(i-2)*(i-1)/2+j-i]=x;
}
int UpperTri::Get(int i,int j)
{
    if(i<=j)
        return A[n*(i-1)-(i-2)*(i-1)/2+j-i];
    else
        return 0;
}
void UpperTri::Display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i<=j)
                cout<<A[n*(i-1)-(i-2)*(i-1)/2+j-i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
//Column Major Method
void UpperTri::Set(int i,int j,int x)
{
    if(i<=j)
        A[j*(j-1)/2+i-1]=x;
}
int UpperTri::Get(int i,int j)
{
    if(i<=j)
        return A[j*(j-1)/2+i-1];
    else
        return 0;
}
void UpperTri::Display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i<=j)
                cout<<A[j*(j-1)/2+i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,x;
    cout<<"Enter dimension: ";
    cin>>n;
    UpperTri T(n);
    cout<<"Enter all elements:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            T.Set(i,j,x);
        }
    }
    cout<<"Matrix is: \n";
    T.Display();
    return 0;
}