//Tridiagonal Matrix (M[i,j]=0      |i-j|<=1)
#include<iostream>
using namespace std;
class Tridiagonal
{
    int n;
    int *A;
    public:
    Tridiagonal(int n)
    {
        this->n=n;
        A=new int[3*n-2];
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~Tridiagonal()
    {
        delete []A;
    }
};
void Tridiagonal::Set(int i,int j,int x)
{
    if(i-j==1)
        A[i-2]=x;
    if(i-j==0)
        A[n-1+i-1]=x;
    if(i-j==-1)
        A[2*n-1+i-1]=x;
}
int Tridiagonal::Get(int i,int j)
{
    if(i-j==1)
        return A[i-2];
    else if(i-j==0)
        return A[n-1+i-1];
    else if(i-j==-1)
        return A[2*n-1+i-1];
    else
        return 0;
}
void Tridiagonal::Display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i-j==1)
                cout<<A[i-2]<<" ";
            else if(i-j==0)
                cout<<A[n-1+i-1]<<" ";
            else if(i-j==-1)
                cout<<A[2*n-1+i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
//Square band matrix of 5 non-zero diagonals
class Sqband
{
    int n;
    int *A;
    public:
    Sqband(int n)
    {
        this->n=n;
        A=new int[5*n-6];
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~Sqband()
    {
        delete []A;
    }
};
void Sqband::Set(int i,int j,int x)
{
    if(i-j==2)
        A[i-3]=x;
    if(i-j==1)
        A[n-2+i-2]=x;
    if(i-j==0)
        A[2*n-3+i-1]=x;
    if(i-j==-1)
        A[3*n-3+i-1]=x;
    if(i-j==-2)
        A[4*n-4+i-1]=x;
}
int Sqband::Get(int i,int j)
{
    if(i-j==2)
        return A[i-3];
    else if(i-j==1)
        return A[n-2+i-2];
    else if(i-j==0)
        return A[2*n-3+i-1];
    else if(i-j==-1)
        return A[3*n-3+i-1];
    else if(i-j==-2)
        return A[4*n-4+i-1];
    else
        return 0;
}
void Sqband::Display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i-j==2)
                cout<<A[i-3]<<" ";
            else if(i-j==1)
                cout<<A[n-2+i-2]<<" ";
            else if(i-j==0)
                cout<<A[2*n-3+i-1]<<" ";
            else if(i-j==-1)
                cout<<A[3*n-3+i-1]<<" ";
            else if(i-j==-2)
                cout<<A[4*n-4+i-1]<<" ";
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
    //Tridiagonal T(n);
    Sqband T(n);
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

