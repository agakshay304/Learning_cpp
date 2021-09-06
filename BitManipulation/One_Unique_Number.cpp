#include <iostream>
using namespace std;


int unique(int a[],int n )
{
    int xorsum=0;
    for(int i=0;i<n;i++)
    {
        xorsum=xorsum^a[i];
    }
    return xorsum;
}

int main()
{
    int a[]={1,1,2,3,2,4,4};
    cout<<unique(a,7);
}