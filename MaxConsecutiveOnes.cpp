#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);

    int n=10;
    int k=2;
    int count=0;
    int j=-1;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            count++;
        }    
            while(count>k)
            {
                j++;
                if(a[j]==0)
                {
                    count--;
                } 
            }
        int len=i-j;
        if(len>ans)
        {
            ans=len;
        }
    }

    cout<<ans<<endl;
}