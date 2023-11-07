#include <bits/stdc++.h>
using namespace std;

string LongestCommonPrefix(vector<string> s)
{
    string st;
    if(s.size()==1)
    {
        return s[0];
    }
    sort(s.begin(),s.end());
    string first=s[0];
    string last=s[s.size()-1];
    int i=0;
    while(first[i]==last[i])
    {
        st.push_back(first[i]);
        i++;
    }
    return st;

}


int main()
{
    vector<string> A;
    A.push_back("abca");
    A.push_back("ab");
    A.push_back("abcd");

    string st=LongestCommonPrefix(A);
    for(int i=0;i<st.size();i++)
    {
        cout<<st[i]<<" ";
    }
}