#include<iostream>
using namespace std;
struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
}*root=NULL;
struct Stack
{
    int Size;
    int top;
    Node **S;
};
void stackcreate(Stack *st,int size)
{
    st->top=-1;
    st->S=new Node*[size];
}
void push(Stack *st,Node *x)
{
    if(st->top==st->Size-1)
        cout<<"Stack Overflow\n";
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}
Node *pop(Stack *st)
{
    Node *x=NULL;
    if(st->top==-1)
        cout<<"Stack Underflow\n";
    else
        x=st->S[st->top--];
    return x;
}
/*void Insert(int key)
{
    Node *t=root;
    Node *r,*p;
    if(root==NULL)
    {
        p=new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else return;
    }
    p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
        r->lchild=p;
    else
        r->rchild=p;
}
*/
void createPre(int pre[],int n)
{
    Node *t,*p;
    Stack st;
    stackcreate(&st,100);
    int i=0;
    root=new Node;
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    while(i<n)
    {
        if(pre[i]<p->data)
        {
            t=new Node;
            t->data=pre[i++];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            push(&st,p);
            p=t;
        }
        else
        {
            if((pre[i]>p->data) && (st.top==0 || pre[i]<st.top))
            {
                t=new Node;
                t->data=pre[i++];
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                p=t;
            }
            else
            {
                p=pop(&st);
            }
        }
    }
}
void preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int main()
{
    int A[8]={30,20,10,15,25,40,50,45};
    createPre(A,8);
    preorder(root);
    return 0;
}