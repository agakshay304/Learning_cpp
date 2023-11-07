#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cout<<"Enter Size Of Array ";
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    //Logic: put a[i] in i

    const int N=1e2+2;
    int idx[N];

    for(int i=0;i<N;i++)
    {
        idx[i]=-1;
    }

    int min_idx=INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(idx[a[i]]!=-1)
        {
                min_idx=min(min_idx,idx[a[i]]);

        }
        else
        {
            idx[a[i]]=i;
        }
    }

    if(min_idx==INT_MAX)
    {
        cout<<"-1"<<endl;

    }
    else
    {
        min_idx++;
    }

    cout<<min_idx<<endl;

}
