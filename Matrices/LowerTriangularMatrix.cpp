//Lower Triangular Matrix (M[i,j]=0     if i<j)
#include<iostream>
using namespace std;
class LowerTri
{
    int n;
    int *A;
    public:
    LowerTri(int n)
    {
        this->n=n;
        A=new int[n];
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~LowerTri()
    {
        delete []A;
    }
};
//Row Major Method
void LowerTri::Set(int i,int j,int x)
{
    if(i>=j)
        A[i*(i-1)/2+j-1]=x;
}
int LowerTri::Get(int i,int j)
{
    if(i>=j)
        return A[i*(i-1)/2+j-1];
    else
        return 0;
}
void LowerTri::Display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i>=j)
                cout<<A[i*(i-1)/2+j-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
//Column Major Method
void LowerTri::Set(int i,int j,int x)
{
    if(i>=j)
        A[n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
}
int LowerTri::Get(int i,int j)
{
    if(i>=j)
        return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
    else
        return 0;
}
void LowerTri::Display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i>=j)
                cout<<A[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
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
    LowerTri T(n);
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