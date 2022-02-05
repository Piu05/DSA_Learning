/*
//Linked List
-It is a collection of nodes where each node contains data and the pointer to next node
-Head is a pointer pointing to first node.

*/
#include<iostream>
using namespace std;
struct Node         //Self-referential structure (structure pointing to itself) 
{
    int data;
    Node *next;
};
int main()
{
    Node *p;
    p=new Node;
    p->data=10;
    p->next=NULL;
    return 0;
}