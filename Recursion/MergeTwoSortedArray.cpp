#include <iostream>
using namespace std;


void mergearray(int a[],int b[])
{
    int i=0;
    int j=0;

    int ans[9];
    int k=0;

    while(i<4 && j<5)
    {
        if(a[i]<b[j])
        {
            ans[k]=a[i];
            i++;
            k++;
        }
        else
        {
             ans[k]=b[j];
            j++;
            k++;
        }
    }

    while(i<4)
    {
        ans[k]=a[i];
            i++;
            k++;
    }

    while(j<5)
    {
         ans[k]=b[j];
            j++;
            k++;
    }

    for(k=0;k<9;k++)
    {
        cout<<ans[k];
    }



}

int main()
{
    int a[]={1,3,5,7};
    int b[]={2,4,6,8,9};

    mergearray(a,b);
}