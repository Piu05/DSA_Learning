//Tower Of Hanoi
//Moving disk/disks from A to C using B
/* 
Using recursion
1 disk given
-Move disk from A to C using B

2 disks given
-TOH(1,A,C,B)                       //here in brackets (disk,source,intermediate,destination)
-move disk from A to C using B
-TOH(1,B,A,C)

3 disks given
-TOH(2,A,C,B)       //Use above methods to move 2 disks from A to B 
-Move disk from A to C using B
-TOH(2,B,A,C)
Time complexity for 3 disks is O(2^n)
*/

//Program
#include<iostream>
using namespace std;
void TOH(int n,int A,int B,int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        cout<<A<<","<<C<<endl;
        TOH(n-1,B,A,C);
    }
}
int main()
{
    int a;
    cout<<"Enter the no. of disks to be moved from Tower 1 to 3: ";
    cin>>a;
    TOH(a,1,2,3);
    return 0;
}