#include<iostream>
#include<math.h>
using namespace std;
struct Node
{
    int coeff;
    int exp;
    Node *next;
}*poly=NULL;
void create()
{
    Node *t,*last=NULL;
    int num;
    cout<<"Enter no. of terms: ";
    cin>>num;
    cout<<"Enter each term with coeff and exp\n";
    for(int i=0;i<num;i++)
    {
        t=new Node;
        cin>>t->coeff>>t->exp;
        t->next=NULL;
        if(poly==NULL)
        {
            poly=t;
            last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
    }
}
void display(Node *p)
{
    while(p)
    {
        cout<<p->coeff<<"x^"<<p->exp<<"+";
        p=p->next;
    }
    cout<<endl;
}
long Eval(Node *p,int x)
{
    long val=0;
    while(p)
    {
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
}
int main()
{
    create();
    display(poly);
    cout<<"\nValue when x=1 : "<<Eval(poly,1);
    return 0;
}