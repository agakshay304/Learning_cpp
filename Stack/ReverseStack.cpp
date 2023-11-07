#include <iostream>
#include <stack>
using namespace std;

void insertatbottom(stack<int> s,int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }
int newele=s.top();
s.pop();
insertatbottom(s,newele);
}


void reverse(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
int ele=s.top();
s.pop();
reverse(s);
insertatbottom(s,ele);

}


int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}