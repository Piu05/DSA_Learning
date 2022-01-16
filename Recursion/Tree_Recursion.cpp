//Tree Recursion
//Time complexity- O(2^n)
//Space complexity- O(n)
#include<iostream>
using namespace std;
void fun(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        fun(n-1);
        fun(n-1);
    }
}
int main()
{
    int x=5;
    fun(x);
    return 0;
}