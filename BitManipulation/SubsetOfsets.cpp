#include <iostream>
using namespace std;

void subset(char a[],int n )
{
   for(int i=0;i<(1<<n);i++)

    {
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                cout<<a[j]<<endl;
            }
        }cout<<endl;
    }
}



int main()
{

    char a[4]={'a','b','c','d'};
    
    subset(a,4);

    
}