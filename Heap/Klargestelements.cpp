#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> klargest(int a[],int k,int n)
{
    priority_queue<int,vector<int>, greater<int> > minh;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        minh.push(a[i]);
        if(minh.size()>k)
        {
            minh.pop();
        }
    }
    while(!minh.empty())
    {
        v.push_back(minh.top());
        minh.pop();
    }
    return v;
}

int main()
{
    int a[]={7,10,4,3,20,15};
    int k=3;
    vector<int> ans=klargest(a,k,6);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }

}