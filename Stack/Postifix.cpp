#include <iostream>
#include <math.h>
#include <stack>
using namespace std;



int postifix(string st)
{
    stack<int> s;
        //Because we go from L to R in postifix.
    for(int i=0;i<st.length();i++)
    {
        if(st[i]>='0' && st[i]<='9')
        {
            s.push(st[i]-'0');          //converts string to int
        }
        else
        {//Because operand 2 will be in top of stack then operand 1.
            int op2=s.top();
            s.pop();
            int op1=s.top();
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
            break;
            }
        }
    }
    return s.top();
}
int main()
{
    string st="46+2/5*7+";
    cout<<postifix(st);
}