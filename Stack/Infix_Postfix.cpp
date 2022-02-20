//Infix to Postfix Comparison
/*
Infix-      a+b     (Human-friendly)
Prefix-     +ab     (Computer-friendly)
Postfix-    ab+     (Computer-friendly)
Associativity-  L-R(left to right) & R-L(right to left)
Unary Operators-  R-L associativity
*/
#include<iostream>
#include<cstring>
using namespace std;
struct Node
{
    char data;
    Node *next;
}*top=NULL;
void push(char x)
{
    Node *t;
    t=new Node;
    if(t==NULL)
        cout<<"Stack Overflow\n";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop()
{
    Node *t;
    char x=-1;
    if(top==NULL)
        cout<<"Stack Underflow\n";
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}
void display()
{
    Node *p;
    p=top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int isOperand(char s)
{
    if(s>='0' &&s<='9')     //For only conversion use 'a' and 'z' instead of '0' and '9'
        return 1;
    else
        return 0;
}
int pre(char s)
{
    if(s=='*'||s=='/')
        return 2;
    else if(s=='+'||s=='-')
        return 1;
    else
        return 0;
}
char* IntoPost(char infix[])
{
    char* post;
    int a=0,i=0,j=0,len;
    while(infix[a++]!='\0')
        len++;
    post=new char[len+2];
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            post[j++]=infix[i++];
        else if(top==NULL)
        {
            push(infix[i++]);
        }      
        else
        {   if(pre(infix[i])>pre(top->data))
                push(infix[i++]);
            else
                post[j++]=pop();
        }
    }
    while(top!=NULL)
        post[j++]=pop();
    post[j]='\0';
    display();
    return post;
}
int main()
{
    char infix[]="2+3*4-8/2";
    cout<<"Postfix: "<<IntoPost(infix);
    return 0;
}