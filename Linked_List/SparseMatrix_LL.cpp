#include<iostream>
using namespace std;
#include<string> 
class Node 
{
    public: 
    int col, val; 
    Node *next; 
    }; 
    void create(int m, int n, Node **a) 
    { 
        int x; 
        Node *t, *last; 
        for(int i=0;i<m;i++) 
        { 
            a[i]=NULL; 
        } 
        cout <<"Enter the values" << endl;
        for(int i=0;i<m;i++) 
        { 
            for(int j=0;j<n;j++) 
            { 
                cin>>x; 
                if(x!=0) 
                { 
                    if(a[i]==NULL) 
                    { 
                        t = new Node; 
                        t->col=j; 
                        t->val=x; 
                        t->next=NULL; 
                        a[i]=t; 
                        last=t; 
                    } 
                    else 
                    { 
                        t = new Node;
                        t->col=j; 
                        t->val=x; 
                        t->next=NULL; 
                        last->next=t; 
                        last=t; 
                    }
                }
            }
        }
    } 
void display(int m, int n, Node *a[]) 
{ 
    Node *p; 
    for(int i=0;i<m;i++)
    {
        p=a[i];
        for(int j=0;j<n;j++)
        {
            if(p && j==p->col) 
            { 
                cout<<p->val<<" "; 
                p=p->next; 
            } 
            else 
            { 
                cout<<"0 "; 
            } 
        } 
        cout<<endl; 
    } 
    cout<<endl; 
} 
int main() 
{ 
    int m, n; 
    cout<<"Enter the number of rows and columns: "<<endl; 
    cin>>m>>n; 
    Node **a; 
    a=new Node *[m]; 
    create(m, n, a); 
    display(m, n, a); 
    return 0; 
}

