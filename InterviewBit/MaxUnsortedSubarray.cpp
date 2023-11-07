//MaxUnsortedSubarray.cpp
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int a[n],d[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>d[i];
        sort(a,a+n);
        sort(d,d+m);
        int i=0,j=0,count=0;
        while(i<n && j<m)
        {
            if(a[i]<=d[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            if(count==k)
                break;
        }
        if(count==k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}