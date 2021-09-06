#include <iostream>
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

string infixtopostifix(string s)
{
    stack<char> st;
    string res="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z')
        {
            res+=s[i];
        }
        else
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else
        if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            //for popping out the opening bracket in the expression.
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
        while(!st.empty() && prec(st.top())>prec(s[i]))
        {
            res+=s[i];
            st.pop();
        }
        st.push(s[i]);
    }
    }
    //tp check if something is left in the stack.
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    return res;
}


int main()
{
    string s="(A-B/C)*(A/K-L)";
    cout<<infixtopostifix(s);
}