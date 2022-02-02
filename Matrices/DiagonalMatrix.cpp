/*
Special Matrices
-Diagonal matrix
-Lower triangular matrix
-Upper triangular matrix
-Symmetric matrix
-Tridiagonal matrix
-Band matrix
-Toeplitz matrix
-Sparse matrix
*/

//Diagonal Matrix (M[i,j]=0     if i!=j)
//Using a 1D array for storing elements
#include<iostream>
using namespace std;
//In C
struct Matrix
{
    int A[10];
    int n;
}; 
void Set(Matrix *m,int i, int j, int x)
{
    if(i==j)
        m->A[i-1]=x;
}
int Get(Matrix m,int i, int j)
{
    if(i==j)
        return m.A[i-1];
    else
        return (0);
}
void Display(Matrix m)
{
    cout<<"Matrix:\n";
    for(int i=1;i<=m.n;i++)
    {
        for(int j=1;j<=m.n;j++)
        {
            if(i==j)
                cout<<m.A[i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    struct Matrix m;
    m.n=4;
    Set(&m,1,1,5);
    Set(&m,2,2,8);
    Set(&m,3,3,10);
    Set(&m,4,4,12);
    cout<<Get(m,2,2)<<endl;
    Display(m);
    return 0;
}

//In C++
class Diagonal
{
    int n;
    int *A;
    public:
    Diagonal(int n)
    {
        this->n=n;
        A=new int[n];
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~Diagonal()
    {
        delete []A;
    }
};
void Diagonal::Set(int i,int j,int x)
{
    if(i==j)
        A[i-1]=x;
}
int Diagonal::Get(int i,int j)
{
    if(i==j)
        return A[i-1];
    else
        return 0;
}
void Diagonal::Display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                cout<<A[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    Diagonal d(4);
    d.Set(1,1,5);
    d.Set(2,2,8);
    d.Set(3,3,10);
    d.Set(4,4,12);
    d.Display();
    return 0;
}