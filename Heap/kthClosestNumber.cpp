/*Input: K = 4, X = 35
       arr[] = {12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56}
Output: 30 39 42 45*/

#include<bits/stdc++.h>
#include<math.h>
#include<vector>
using namespace std;

void kclosest(int a[],int k,int n,int x)
{
    priority_queue<pair<int,int> > maxh;
    for(int i=0;i<n;i++)
    {
        maxh.push(make_pair(abs(a[i]-x),a[i]));
        if(maxh.size()>k)
        {
            maxh.pop();
        }
    }
    while(!maxh.empty())
    {
        cout<<maxh.top().second<<endl;
        maxh.pop();
    }
}

int main()
{
    int K = 3, X = 7;
       int arr[] = {5,6,7,8,9};
    
    kclosest(arr,K,5,X);

}