#include <iostream>
#include <vector>
using namespace std;


vector<int> addOneToNumber(int a[],int n)
{
    vector<int> res;
    res.push_back((a[n-1]+1)%10);
    int carry=(a[n-1]+1)/10;

    for(int i=n-2;i>=0;i--)
    {
        res.push_back((carry+a[i])%10);
        carry=(carry+a[i])/10;
    }
    if(carry)
    {
        res.push_back(carry);
    }
    for(int i=0;i<(res.size())/2;i++)
    {
        swap(res[i],res[(res.size())-i-1]);
    }
    while(res[0]==0)
    {
        res.erase(res.begin());
    }
    return res;
}


int main()
{
    int a[]={9,9,9,9};
    vector<int> ans=addOneToNumber(a,4);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }
    return 0;
}