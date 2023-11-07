#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > pi;
vector<int> mergeKsorted(vector<vector<int> > a,int k)
{
    priority_queue<pi,vector<pi>,greater<pi> > minh;

    vector<int> v;

    for(int i=0;i<k;i++)
    {
        minh.push(make_pair(a[i][0],make_pair(i,0)));
    }
    while(!minh.empty())
    {
        pi x=minh.top();
        minh.pop();

        v.push_back(x.first);

        int row=x.second.first;
        int col=x.second.second;

        if(col<k-1)
        {
            minh.push(make_pair(a[row][col+1],make_pair(row,col+1)));
        }
    }
    return v;
}

int main()
{
    vector<vector<int> > a={{1,2,3},{4,5,6},{7,8,9}};
    int k=3;

    vector<int> ans=mergeKsorted(a,k);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}