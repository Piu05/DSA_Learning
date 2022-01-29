//Introduction to strings
/*
-ASCII code (0-127)
For every letter, digit and symbol we have a numeric code which is called ASCII code
It is for english language
It takes 1 byte of memory
A-Z = 65-90
a-z = 97-122
0-9 = 48-57

-Unicodes
It is for all language
It takes 2 bytes of memory (16-bits)

-String
A set of characters is called string
A string ends with a null character '\0'
Syntax:
char name[10]={'J','o','h','n','\0'};
char name[]={'J','o','h','n','\0'};
char name[]="John";  
*/
#include<iostream>
using namespace std;
int main()
{
    char A[]="Priyanka";
    //Finding length of string
    int count=0;
    for(int i=0;A[i]!='\0';i++)
    {
        count++;
    }
    cout<<"String size is: "<<count;
    //Changing case of a string (or toggle) 
    char B[10]="WeLcOmE";
    for(int i=0;B[i]!='\0';i++)
    {
        if(B[i]>=65 && B[i]<=90)
            B[i]+=32;
        else if(B[i]>=97 && B[i]<=122)
            B[i]-=32;
    }
    cout<<"\nAfter changing case string is = "<<B;
    //Count no. of vowels and consonents in a string
    char C[]="Today is a nice day";
    int count1=0,count2=0;
    for(int i=0;C[i]!='\0';i++)
    {
        if(C[i]=='a'||C[i]=='e'||C[i]=='i'||C[i]=='o'||C[i]=='u'||C[i]=='A'||C[i]=='E'||C[i]=='I'||C[i]=='O'||C[i]=='U')
            count1++;
        else if((C[i]>=65 && C[i]<=90)||(C[i]>=97 && C[i]<=122))
            count2++;
    }
    cout<<"\nNo. of vowels = "<<count1;
    cout<<"\nNo. of consonents = "<<count2;
    //Count no. of words in a string
    int word=0;
    for(int i=0;C[i]!='\0';i++)
    {
        if(C[i]==' ' && C[i-1]!=' ')
            word++;
    }
    cout<<"\nNo. of words in a string = "<<word+1;
    return 0;
}