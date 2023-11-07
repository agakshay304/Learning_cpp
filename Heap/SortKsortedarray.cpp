/*Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
            k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50}
         k = 4
Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}*/

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
            v.push_back(minh.top());
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
    int a[]={6,5,3,2,8,10,9};
    int k=3;
    vector<int> ans=klargest(a,k,7);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }

}