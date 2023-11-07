#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int leastcostrope(int a[],int n)
{
    priority_queue<int,vector<int>,greater<int> > minh;
    int cost=0;
    for(int i=0;i<n;i++)
    {
        minh.push(a[i]);
    }
    while(minh.size()>=2)
    {
        int first=minh.top();
        minh.pop();
        int second=minh.top();
        minh.pop();
        cost=cost+first+second;
        minh.push(first+second);
    }
    return cost;
}

int main()
{
    int a[]={1,2,3,4,5};
    int ans=leastcostrope(a,5);

    cout<<ans<<endl;
}