#include <iostream>
using namespace std;

int setBit(int n,int pos )
{
    return ((n & (1<<pos))!=0);
}
void unique(int a[],int n )
{
    int xorsum=0;
    for(int i=0;i<n;i++)
    {
        xorsum=xorsum^a[i];
    }
    int tempxor=xorsum;
    int pos=0;
    int setbit=0;
    //for checking the position of rightmost set bit.
    while(setbit!=1)
    {
        setbit=xorsum & 1;
        pos++;
        xorsum=xorsum >> 1;
    }
    //for iterating to every number & xorsum of set bit at that position.
    int newxor=0;
    for(int i=0;i<n;i++)
    {
        if(setBit(a[i],pos-1))
        {
            newxor=newxor^a[i];
        }
    }

    cout<<newxor<<endl;
    cout<<(newxor^tempxor)<<endl;
}

int main()
{
    int a[]={1,1,2,3,2,4,4,5};
    unique(a,8);
}