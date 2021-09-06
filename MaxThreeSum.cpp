#include <bits/stdc++.h>
#include <vector>
using namespace std;


bool threesum(vector<int> a,int k)
{
    int n=a.size();
    int left=1;
    int right=n-1;
    int ans;
for(int i=0;i<n;i++)
{
    while(left<=right)
    {
        ans=a[i]+a[left]+a[right];
        if(ans==k)
        {
            return true;
        }
        else
        if(ans<k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
}
return false;

}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    a.push_back(9);
    a.push_back(11);
    
    cout<<threesum(a,9);
}