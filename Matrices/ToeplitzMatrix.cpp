//Toeplitz Matrix (M[i,j]=M[i-1,j-1])
#include<iostream>
using namespace std;
class Toeplitz
{
    int n;
    int *A;
    public:
    Toeplitz(int n)
    {
        this->n=n;
        A=new int[2*n-1];
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~Toeplitz()
    {
        delete []A;
    }
};
void Toeplitz::Set(int i,int j,int x)
{
    if(i<=j)
        A[j-i]=x;
    if(i>j)
        A[n+i-j-1]=x;
}
int Toeplitz::Get(int i,int j)
{
    if(i<=j)
        return A[j-i];
    else if(i>j)
        return A[n+i-j-1];
    else
        return 0;
}
void Toeplitz::Display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i<=j)
                cout<<A[j-i]<<" ";
            else if(i>j)
                cout<<A[n+i-j-1]<<" ";
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
    Toeplitz T(n);
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