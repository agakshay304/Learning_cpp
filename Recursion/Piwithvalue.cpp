#include <iostream>
#include <string>
using namespace std;

void pivalue(string s)
{

    if(s.length()==0)
    {
        return;
    }

    
        if(s[0]=='p' && s[1]=='i')
        {
            cout<<"3.14";
            pivalue(s.substr(2));
        }
    else
    {
        cout<<s[0];
        pivalue(s.substr(1));
    }
}




int main()
{
    pivalue("pipipxxxxpxxpi");
}