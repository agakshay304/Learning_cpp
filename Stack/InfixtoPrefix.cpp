//Concept is all same as InfixtoPostifix only diff is that we have to
//reverse the expression first along with their braces and then when 
//we will store the answer we will reverse that too.


#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else
    if(c=='*' || c=='/')
    {
        return 2;
    }
    else
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixtoprefix(string s)
{
    reverse(s.begin(),s.end());
    stack<char> st;
    string res="";
    //Trick:We will write the same code as of infixtopostifix at last
    //we will refactor the opening and closing braces.
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z')
        {
            res+=s[i];
        }
        else
        if (s[i]==')')
        {
            st.push(s[i]);
        }
        else
        if(s[i]=='(')
        {
            while(!st.empty() && st.top()!=')')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && prec(st.top())>prec(s[i]))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}


int main()
{
    string s="(A-B/C)*(A/K-L)";
    cout<<infixtoprefix(s);
}