#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;


int maxarea(vector<int>& height)
{
    int n=height.size();
    vector<int> left(n),right(n);

    stack<int> st;


    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            left[i]=0;
            st.push(i);
        }
        else{
            while(!st.empty() && height[st.top()]>=height[i])
            {
                st.pop();
            }
            left[i]=st.empty()?0:st.top()+1;
            st.push(i);
        }
    }

    while(!st.empty())
    {
        st.pop();
    }

    for(int i=n-1;i>=0;i--)
    {
        if(st.empty())
        {
            right[i]=n-1;
            st.push(i);
        }
        else
        {
            while(!st.empty() && height[st.top()]>=height[i])
            {
                st.pop();
            }
            right[i]=st.empty()?n-1:st.top()-1;
            st.push(i);
        }
    }
    int maxarea=0;
    for(int i=0;i<n;i++)
    {
        maxarea=max(maxarea,height[i]*(right[i]-left[i]+1));
    }
    return maxarea;
}

int main()
{
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);
    int max=maxarea(heights);
    cout<<max;
}