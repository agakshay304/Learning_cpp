#include <iostream>
#include <string>
#include <queue>
using namespace std;


bool checkrotation(string s1,string s2)
{
    if(s1.length()==s2.length())
    {
    queue<char> q1;
    for(int i=0;i<s1.length();i++)
    {
        q1.push(s1[i]);
    }
    queue<char> q2;
    for(int j=0;j<s2.length();j++)
    {
        q2.push(s2[j]);
    }

    int ql=s2.length();
    while(ql--)
    {
        char ch=q2.front();
        q2.pop();
        q2.push(ch);

        if(q1==q2)
        {
            return true;
        }
    }
    return false;
    }
}

int main()
{
    string s1="abcd";
    string s2="cdab";

    cout<<checkrotation(s1,s2)<<endl;
}