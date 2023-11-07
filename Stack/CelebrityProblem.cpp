//Celebrity Problem
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> v;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            s.push(a[i]);
        }
        else
        {
            if(s.top()==a[i])
            {
                s.pop();
            }
            else
            {
                s.push(a[i]);
            }
        }
    }
    if(s.empty())
    {
        cout<<"No celebrity";
    }
    else
    {
        cout<<s.top();
    }
    return 0;
}