//Creating a binary tree
#include<iostream>
#include<stdio.h>
using namespace std;
struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
}*root=NULL;
struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};
void create(Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new Node*[size];
}
void enqueue(Queue *q,Node* x)
{
    if((q->rear+1)%q->size==q->front)
        cout<<"\nQueue is full";
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
Node* dequeue(Queue *q)
{
    Node* x=NULL;
    if(q->front==q->rear)
        cout<<"\nQueue is empty";
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(Queue q)
{
    return q.front==q.rear;
}
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
int isEmptyStack(Stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}
void Create()
{
    Node *p,*t;
    int x;
    Queue q;
    create(&q,100);
    cout<<"\nEnter root value :";
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        cout<<"\nEnter left child of "<<p->data<<" :";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        cout<<"\nEnter right child of "<<p->data<<" :";
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
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
void IPreorder(Node *p)
{
    Stack stk;
    stackcreate(&stk,100);
    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            cout<<p->data<<" ";
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }    
    }
}
void inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
void postorder(Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}
void Levelorder(Node *p)
{
    Queue Q;
    create(&Q,100);
    cout<<p->data<<" ";
    enqueue(&Q,p);
    while(!isEmpty(Q))
    {
        p=dequeue(&Q);
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            enqueue(&Q,p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            enqueue(&Q,p->rchild);
        }
    }
}
int main()
{
    Create();
    cout<<"Preorder: ";
    preorder(root);
    IPreorder(root);
    cout<<"\nInorder: ";
    inorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
    cout<<"\nLevelorder: ";
    Levelorder(root);
    return 0;
}

//In C++ use class and change functions accordingly
