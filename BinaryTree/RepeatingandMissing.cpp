#include <bits/stdc++.h>
using namespace std;


void repmiss(int a[],int n)
{
    bool check[n+1];
    int rep,mis;
    for(int i=0;i<=n;i++)
    {
        check[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(check[i]==true)
        {
         rep=a[i];
        }
        check[a[i]]=true;
    }

    for(int i=1;i<=n;i++)
    {
        if(check[i]==false)
        {
             mis=i;
            break;
        }
    }
    cout<<rep<<endl;
    cout<<mis<<endl;
}

int main()
{
    int a[]={1,2,2,4};
    int n=4;

    repmiss(a,n);
}