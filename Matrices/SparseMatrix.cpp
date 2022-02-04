//Sparse Matrix
/*
-Representation
-Addition of 2 sparse matrices
*/
#include<iostream>
using namespace std;
class Element
{
    public:
    int i;
    int j;
    int x;
};
class Sparse
{
    int m;
    int n;
    int num;
    Element *e;
    public:
    void Create();
    void Display();
};
void Sparse::Create()
{
    cout<<"\nEnter dimensions m x n: ";
    cin>>m>>n;
    cout<<"\nEnter no. of non-zero elements: ";
    cin>>num;
    e=new Element[num];
    cout<<"\nEnter all elements in order 'row' 'column' 'element'\n";
    for(int i=0;i<num;i++)
    {
        cin>>e[i].i>>e[i].j>>e[i].x;
    }
}
void Sparse::Display()
{
    int k=0;
    cout<<"Matrix is: \n";
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==e[k].i && j==e[k].j)
                cout<<e[k++].x<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    Sparse S;
    S.Create();
    S.Display();
    return 0;
}
