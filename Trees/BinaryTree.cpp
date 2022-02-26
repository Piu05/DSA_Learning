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
int main()
{
    Create();
    cout<<"Preorder: ";
    preorder(root);
    cout<<"\nInorder: ";
    inorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
    return 0;
}

//In C++ use class and change functions accordingly
