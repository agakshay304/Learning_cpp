#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cout<<"Enter Size ";
    cin>>n;
        int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int N=1e2+2;
    bool check[N];

    for(int i=0;i<N;i++)
    {
        check[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            check[a[i]]=1;
        }
    }
    int ans=-1;

    for(int i=1;i<N;i++)
    {
        if(check[a[i]]==0)
        {
            ans=i;
            break;
        }
    }
     
     cout<<"Missing No. is: "<<ans<<endl;

}