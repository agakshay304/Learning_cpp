#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
 bool reduntant(string s)
 {
     stack<char> st;
     for(int i=0;i<s.length();i++)
     {
         if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')
         {
             st.push(s[i]);
         }
         else
         if(s[i]=='(')
         {
             st.push(s[i]);
         }  
         else
         if(s[i]==')')  
         {
             if(st.top()=='(')
             {
                 return true;
             }
             while(st.top()=='+' || st.top()=='-' || st.top()=='/' || st.top()=='*')
             {
                 st.pop();
             }
             st.pop(); //For removing opening braces
         }
     }
     return false;
 }

 int main()
 {
     //string s="((a+b))";
     //cout<<reduntant(s);
     string s="(a+b)";
     cout<<reduntant(s);

 }