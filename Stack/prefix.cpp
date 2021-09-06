#include <iostream>
#include <math.h>
#include <stack>
using namespace std;



int prefix(string st)
{
    stack<int> s;

    for(int i=st.length()-1;i>=0;i--)
    {
        if(st[i]>='0' && st[i]<='9')
        {
            s.push(st[i]-'0');          //converts string to int
        }
        else
        {
            int op1=s.top();
            s.pop();
            int op2=s.top();
            s.pop();

            switch (st[i])
            {
            case '+':s.push(op1+op2);
                break;
            case '-':s.push(op1-op2);
                break;
            case '*':s.push(op1*op2);
                break;
            case '/':s.push(op1/op2);
            default:cout<<"Not a valid operator";
                break;
            }
        }
    }
    return s.top();
}
int main()
{
    string st="-+7*45+20";
    cout<<prefix(st);
}
