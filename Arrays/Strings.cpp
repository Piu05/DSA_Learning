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
//Check if string is valid
int Valid(char s[10])
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(!(s[i]>=65 && s[i]<=90 && s[i]<=97 && s[i]>=122 && s[i]<=48 && s[i]>=57))
        return 0;
        else
        return 1;
    }
}
//Reverse a string
void Reverse(char P[15])
{
    int i,len=0,j;
    char S;
    for(i=0;P[i]!='\0';i++)
    {
        len++;
    }
    for(i=0,j=len-1;i<j;i++,j--)
    {
        S=P[i];
        P[i]=P[j];
        P[j]=S;
    }
    cout<<"\nAfter reversing, string is: "<<P;
}
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
    //Count no. of vowels and consonants in a string
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
    cout<<"\nNo. of consonants = "<<count2;
    //Count no. of words in a string
    int word=0;
    for(int i=0;C[i]!='\0';i++)
    {
        if(C[i]==' ' && C[i-1]!=' ')
            word++;
    }
    cout<<"\nNo. of words in a string = "<<word+1;
    //Validate a string
    char name[10]="Pink!123";
    if(Valid(name)==1)
        cout<<"\nValid string";
    else
        cout<<"\nInvalid string";
    //Reverse a string
    char P[15]="structure";
    Reverse(P);
    //Comparing strings
    char S[]="Painter";
    char T[]="Painter";
    int i,j;
    for(i=0,j=0;S[i]!='\0';i++,j++)
    {
        if(S[i]!=T[j])
        {   cout<<"\nStrings are not same";
            break;
        }
    }
    if(S[i]==T[j])
        cout<<"\nSame strings";
    else if(S[i]<T[j])
        cout<<"\nFirst string is smaller";
    else
        cout<<"\nFirst string is greater";
    //Checking palindrome
    char Pa[]="madam";
    int c=0;
    for(int i=0;Pa[i]!='\0';i++)
    {
        c++;
    }
    for(i=0,j=c-1;i<j;i++,j--)
    {
        if(Pa[i]!=Pa[j])
        {
            cout<<"\nNot palindrome";
            break;
        }
    }
    if(i>=j)
        cout<<"\nPalindrome";
    //Duplicates in string
    char D[]="finding";
    char ch;
    int Hash[26]={0};
    for(int i=0;D[i]!='\0';i++)
    {
        Hash[D[i]-97]+=1;
    }
    for(int i=0;i<26;i++)
    {
        if(Hash[i]>1)
        {
            ch=i+97;
            cout<<"\n"<<ch<<" is repeating "<<Hash[i]<<" times";
        }
    }
    //Duplicates in string using bitwise operation
    /*
    Bitwise operations-&(AND),|(OR),Masking(checking whether bit is ON(1) or not using ANDing),Merging(making a bit ON(1))
    H=1 [0 0 0 0 0 0 1] in bits
    H=H<<2 means shifting 1 to left by 2 positions
    H=H<<1 means shifting 1 to left by 1 position
    */
    int H=0,x=0,I=0;
    for(int f=0;D[f]!='\0';f++)
    {
        x=1;
        x=x<<(D[f]-97);
        if((x&H)>0)
        {
            if((x&I)==0)
            {
                cout<<"\n"<<D[f]<<" is duplicate";
                I=I|x;
            }
        }
        else
            H=(x|H);
    }
    //Checking if strings are anagram
    char P1[]="verbose";
    char P2[]="observe";
    int Hh[26]={0};
    for(int i=0;P1[i]!='\0';i++)
    {
        Hh[P1[i]-97]+=1;
    }
    for(i=0;P2[i]!='\0';i++)
    {
        Hh[P2[i]-97]-=1;
        if(Hh[P2[i]-97]<0)
        {   
            cout<<"\nStrings are not anagram";
            break;
        }
    }
    if(P2[i]=='\0')
        cout<<"\nStrings are anagram";
    //Checking string is anagram using bitwise
    int Z=0,X=0,Y=0;
    for(i=0;P1[i]!='\0';i++)
    {
        X=1;
        X=X<<(P1[i]-97);
        Z=X|Z;
    }
    for(i=0;P1[i]!='\0';i++)
    {
        Y=1;
        Y=Y<<(P2[i]-97);
        if((Z&Y)==0)
        {
            cout<<"\nNot anagram";
            break;
        }
    }
    if(P1[i]=='\0')
        cout<<"\nAnagram";
    return 0;
}