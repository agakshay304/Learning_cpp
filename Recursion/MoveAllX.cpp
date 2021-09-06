#include <iostream>
#include <string>
using namespace std;

string movex(string s)
{

    if(s.length()==0)
    {

        return "";
    }
    char ch=s[0];
    string ans=movex(s.substr(1));
    if(ch == 'X')
    return (ans+ch);
    else
    return (ch+ans);
}
int main()
{
    string s="XXAKSXXHAYXX";
    cout<<movex(s);

}