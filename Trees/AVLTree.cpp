//AVL Trees
/*
AVL Tree:
-Height balanced binary search trees
-Balance factor should be {-1,0,1}
Rotations:
-LL Rotation
-RR Rotation
-LR Rotation
-RL Rotation
*/
#include<iostream>
using namespace std;
struct Node
{
    Node *lchild;
    int data;
    int height;
    Node *rchild;
}*root=NULL;
int NodeHeight(Node *p)
{
    int hl,hr;
    if(p && p->lchild)
        hl=p->lchild->height;
    else
        hl=0;
    if(p && p->rchild)
        hr=p->rchild->height;
    else
        hr=0;
    if(hl>hr)
        return hl+1;
    else
        return hr+1;
}
int BalanceF(Node *p)
{
    int hl,hr;
    if(p && p->lchild)
        hl=p->lchild->height;
    else
        hl=0;
    if(p && p->rchild)
        hr=p->rchild->height;
    else
        hr=0;
    return hl-hr; 
}
Node * LLrotation(Node *p)
{
    Node *pl=p->lchild;
    Node *plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root==p)
        root=pl;
    return pl;
}
Node * LRrotation(Node *p)
{
    Node *pl=p->lchild;
    Node *plr=pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);
    if(root==p)
        root=plr;
    return plr;
}
Node * RRrotation(Node *p)
{
    Node *pr=p->rchild;
    Node *prl=pr->lchild;
    pr->lchild=p;
    p->rchild=prl;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    if(root==p)
        root=pr;
    return pr;
}
Node * RLrotation(Node *p)
{
    Node *pr=p->rchild;
    Node *prl=pr->lchild;
    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;
    prl->rchild=pr;
    prl->lchild=p;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);
    if(root==p)
        root=prl;
    return prl;
}
Node * RInsert(Node *p,int key)
{
    Node *t=NULL;
    if(p==NULL)
    {
        t=new Node;
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=RInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=RInsert(p->rchild,key);
    p->height=NodeHeight(p);
    if(BalanceF(p)==2 && BalanceF(p->lchild)==1)
        LLrotation(p);
    else if(BalanceF(p)==2 && BalanceF(p->lchild)==-1)
        LRrotation(p);
    else if(BalanceF(p)==-2 && BalanceF(p->lchild)==-1)
        RRrotation(p);
    else if(BalanceF(p)==-2 && BalanceF(p->lchild)==1)
        RLrotation(p);
    return p;
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
int main()
{
    root=RInsert(root,30);
    RInsert(root,40);
    RInsert(root,35);
    inorder(root);
    return 0;
}