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
    Sparse add(Sparse S1);
    ~Sparse()
    {
        delete [] e;
    }
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
/*We can also convert create and display into friend function
For that: 
inside class we should write 
friend istream & operator>>(istream &is,Sparse &s);
friend ostream & operator<<(ostream &os,Sparse &s);
and we should change 
void Sparse::Create()   into   istream & operator>>(istream &is,Sparse &s) and add return is; in last
void Sparse::Display()  into   ostream & operator<<(ostream &os,Sparse &s) and add return os; in last
so
instead of create() and display() in main function we can write cin>>S and cout<<S
*/
Sparse Sparse::add(Sparse S1)
{
    Sparse *sum;
    if(m!=S1.m || n!=S1.n)
        exit (0);
    sum=new Sparse;
    sum->m=m;
    sum->n=n;
    sum->e=new Element[num+S1.num];
    int i,j,k;
    i=j=k=0;
    while(i<num && j<S1.num)
    {
        if(e[i].i<S1.e[j].i)
            sum->e[k++]=e[i++];
        else if(e[i].i>S1.e[j].i)
            sum->e[k++]=S1.e[j++];
        else
        {
            if(e[i].j<S1.e[j].j)
                sum->e[k++]=e[i++];
            else if(e[i].j>S1.e[j].j)
                sum->e[k++]=S1.e[j++];   
            else
            {
                sum->e[k]=e[i];
                sum->e[k++].x=e[i++].x+S1.e[j++].x;
            }
        }
    }
    for(;i<num;i++)
        sum->e[k++]=e[i];
    for(;j<S1.num;j++)
        sum->e[k++]=S1.e[j];
    sum->num=k;
    return *sum;
}
int main()
{
    Sparse S,S1;
    Sparse sum;
    S.Create();
    S1.Create();
//    S.Display();
    sum=S.add(S1);
    sum.Display();
    return 0;
}
