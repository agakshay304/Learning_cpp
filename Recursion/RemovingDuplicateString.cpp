#include <iostream>
#include <string>
using namespace std;

string duplicatestring(string s)
{
if(s.length()==0)
{
    return " " ;
}
char ch=s[0];
string dupstr=duplicatestring(s.substr(1));

if(ch==dupstr[0])
{
    return dupstr;
}
else
{
    return (ch+dupstr);
}
 
}


int main()
{
    string s="AAAkssHHay";
    cout<<duplicatestring(s);
}
