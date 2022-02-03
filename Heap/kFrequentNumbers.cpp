/*arr[] = {3, 1, 4, 4, 5, 2, 6, 1}, 
k = 2
Output: 4 1*/

#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
using namespace std;

void kfreq(int a[],int k,int n)
{
    priority_queue<pair<int,int>,vector<pair<int,int > >, greater<pair<int,int > > > minh;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        minh.push(make_pair(i->second,i->first));
        if(minh.size()>k)
        {
            minh.pop();
        }
    }
    while(!minh.empty())
    {
       cout<<minh.top().second<<endl;
        minh.pop();
    }
}

int main()
{
    int a[]={3, 1, 4, 4, 5, 2, 6, 1};
    int k=2;
    kfreq(a,k,8);
}