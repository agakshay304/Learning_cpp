#include <iostream>
using namespace std;

bool arraysorted(int a[],int n)
{

    int i=0;

    if(n==1)
    {
        return true;
    }
        
        bool prevsort=arraysorted(a+1,n-1);
        
        return  (a[0]<a[1] && prevsort);
}

int main()
{
    int a[]={1,0,4,5,6,7};


       cout<< arraysorted(a,6)<<endl;
    return 0;
}
