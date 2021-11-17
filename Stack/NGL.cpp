#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> ngl(int a[],int n)
{
    vector<int> v;
    stack<int> s;

    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            v.push_back(-1);
            s.push(i);
        }
        else if(!s.empty() && a[s.top()]<a[i])
        {
            while(!s.empty() && a[s.top()]<a[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                v.push_back(-1);
                s.push(i);
            }
            else
            {
                v.push_back(s.top());
                s.push(i);
            }
        }
        else
        {
            v.push_back(s.top());
            s.push(i);
        }
    }

    return v;

}

int main()
{
    int a[]={24,11,13,21,3};

    vector<int> v=ngl(a,5);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    cout<<endl;
}