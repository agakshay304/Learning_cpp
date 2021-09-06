#include <iostream>
#include <string>
using namespace std;

void reversestring(string s)
{

        if(s.length()==0)
        {
            return;
        }

    
    string newstr=s.substr(1);
    reversestring(newstr);
    cout<<s[0];
}



int main()
{
    reversestring("BINOD");
}